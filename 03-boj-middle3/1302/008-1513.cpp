#include <iostream>

#define LEN 51

using namespace std;

int cross[2][2]={{1,0},{0,1}};

int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    int arr[LEN][LEN]={0};
    for(int i=1;i<=c;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]=i;
    }
    int dp[LEN][LEN][LEN][LEN]={0};
    int rem=1'000'007;
    if(arr[1][1]==0)
    {
        dp[1][1][0][0]=1;
    }
    else
    {
        dp[1][1][1][arr[1][1]]=1;
    }
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=m;y++)
        {
            for(int i=0;i<=c;i++)
            {
                for(int j=0;j<=c;j++)
                {
                    if(dp[x][y][i][j]==0) continue;
                    int cur=dp[x][y][i][j];
                    for(int k=0;k<2;k++)
                    {
                        int xp=x+cross[k][0];
                        int yp=y+cross[k][1];
                        if(xp>n || yp>m) continue;
                        if(arr[xp][yp]==0)
                        {
                            dp[xp][yp][i][j]+=cur;
                            dp[xp][yp][i][j]%=rem;
                        }
                        else
                        {
                            int next=arr[xp][yp];
                            if(j>=next) continue;
                            dp[xp][yp][i+1][next]+=cur;
                            dp[xp][yp][i+1][next]%=rem;
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0;i<=c;i++)
    {
        int res=0;
        for(int j=0;j<=c;j++)
        {
            res+=dp[n][m][i][j];
            res%=rem;
        }
        cout<<res<<" ";
    }
}