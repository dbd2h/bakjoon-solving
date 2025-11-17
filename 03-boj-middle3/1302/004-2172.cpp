#include <iostream>

using namespace std;

int octo[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

int main()
{
    int dp[20][20][20][20]={0};
    int n,l;
    cin>>n>>l;
    int arr[20][20];
    int idx;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    if(l%2==1)
    {
        idx=3;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j][i][j]=1;
            }
        }
    }
    else
    {
        idx=4;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<8;k++)
                {
                    int xp=i+octo[k][0];
                    int yp=j+octo[k][1];
                    if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
                    if(arr[i][j]!=arr[xp][yp]) continue;
                    dp[i][j][xp][yp]=1;
                }
            }
        }
    }
    for(;idx<=l;idx+=2)
    {
        int dpC[20][20][20][20];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    for(int m=0;m<n;m++)
                    {
                        dpC[i][j][k][m]=dp[i][j][k][m];
                        dp[i][j][k][m]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    for(int m=0;m<n;m++)
                    {
                        if(dpC[i][j][k][m]==0) continue;
                        for(int a=0;a<8;a++)
                        {
                            int xp1=i+octo[a][0];
                            int yp1=j+octo[a][1];
                            if(xp1<0 || xp1>=n || yp1<0 || yp1>=n) continue;
                            for(int b=0;b<8;b++)
                            {
                                int xp2=k+octo[b][0];
                                int yp2=m+octo[b][1];
                                if(xp2<0 || xp2>=n || yp2<0 || yp2>=n) continue;
                                if(arr[xp1][yp1]!=arr[xp2][yp2]) continue;
                                dp[xp1][yp1][xp2][yp2]+=dpC[i][j][k][m];
                            }
                        }
                    }
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                for(int m=0;m<n;m++)
                {
                    res+=dp[i][j][k][m];
                }
            }
        }
    }
    cout<<res;
}