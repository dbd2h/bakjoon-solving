#include <iostream>

typedef long long ll;

using namespace std;

ll hexa[6][2]={{-1,0},{1,0},{0,1},{1,1},{0,-1},{-1,-1}};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll dp[15][29][29]={0};
    dp[0][14][14]=1;
    for(int i=0;i<14;i++)
    {
        for(int x=0;x<29;x++)
        {
            for(int y=0;y<29;y++)
            {
                if(dp[i][x][y]==0) continue;
                for(int j=0;j<6;j++)
                {
                    int xp=x+hexa[j][0];
                    int yp=y+hexa[j][1];
                    if(xp<0 || xp>=29 || yp<0 || yp>=29) continue;
                    dp[i+1][xp][yp]+=dp[i][x][y];
                }
            }
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int num;
        cin>>num;
        cout<<dp[num][14][14]<<"\n";
    }
}