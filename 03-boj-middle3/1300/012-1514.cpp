#include <iostream>
#include <string>
#include <vector>

using namespace std;

void makeDp(int dp[][10][10][10], int cur, int turn, bool isL, int c)
{
    
}   

void makeSpin(vector<pair<int,int>> (spin)[], int count, int a, int b, int c, bool check[10][10][10])
{
    if(count==0 && !check[a][b][c])
    {
        spin[a].push_back({b,c});
        check[a][b][c]=1;
    }
    if(count==1 && !check[a][b][c])
    {
        spin[a].push_back({b,c});
        check[a][b][c]=1;
    }
    if(count==2 && !check[a][b][c])
    {
        if(a<4) return;
        spin[a].push_back({b,c});
        check[a][b][c]=1;
    }
    if(count==3 && !check[a][b][c])
    {
        if(a<7) return;
        spin[a].push_back({b,c});
        check[a][b][c]=1;
        return;
    } 
    if(count==3) return;
    for(int i=1;i<=3;i++)
    {
        makeSpin(spin,count+1,a+i,b+i,c+i,check);
        makeSpin(spin,count+1,a+i,b+i,c,check);
        makeSpin(spin,count+1,a+i,b,c,check);
    }
    
}

int main()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int dp[102][10][10][10];
    vector<pair<int,int>> spin[10]; 
    bool check[10][10][10]={0};
    makeSpin(spin,0,0,0,0,check);
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++) dp[i][j][k][l]=-1;
            }
        }
    }
    int s1Init[3];
    for(int i=0;i<3;i++)
    {
        int s1Len=s1.size();
        if(i>=s1Len)
        {
            s1Init[i]=0;
            continue;
        } 
        s1Init[i]=s1[i]-'0';
    }
    
    dp[0][s1Init[0]][s1Init[1]][s1Init[2]]=0;
    for(int i=0;i<n;i++)
    {
        for(int a=0;a<10;a++)
        {
            for(int b=0;b<10;b++)
            {
                for(int c=0;c<10;c++)
                {
                    if(dp[i][a][b][c]==-1) continue;
                    int goal=s2[i]-'0';
                    int left=(goal-a+10)%10;
                    int right=(a-goal+10)%10;
                    int arr[3];
                    int lC=(left-1)/3+1;
                    int rC=(right-1)/3+1;
                    if(left==0) lC=0;
                    if(right==0) rC=0;
                    int next=0;
                    if(s1.size()>i+3)
                    {
                        next=s1[i+3]-'0';
                    }
                    for(int j=0;j<spin[left].size();j++)
                    {
                        int bp=(b+spin[left][j].first)%10;
                        int cp=(c+spin[left][j].second)%10;
                        int sumV=dp[i][a][b][c]+lC;
                        if(dp[i+1][bp][cp][next]==-1 || dp[i+1][bp][cp][next]>sumV)
                        {
                            dp[i+1][bp][cp][next]=sumV;
                        }

                    }
                    for(int j=0;j<spin[right].size();j++)
                    {
                        int bp=(b-spin[right][j].first+10)%10;
                        int cp=(c-spin[right][j].second+10)%10;
                        int sumV=dp[i][a][b][c]+rC;
                        if(dp[i+1][bp][cp][next]==-1 || dp[i+1][bp][cp][next]>sumV)
                        {
                            dp[i+1][bp][cp][next]=sumV;
                        }
                    }
                }
            }
        }
    }
    int res=1e9;
    for(int a=0;a<10;a++)
    {
        for(int b=0;b<10;b++)
        {
            for(int c=0;c<10;c++)
            {
                int cur=dp[n][a][b][c];
                if(cur==-1) continue;
                if(res>cur) res=cur;
            }
        }
    }
    cout<<res;
}