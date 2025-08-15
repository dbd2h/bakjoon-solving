#include <iostream>
#include <algorithm>

using namespace std;
void program()
{
    int n,m;
    cin>>n>>m;
    int sArr[20]={0};
    for(int i=0;i<m;i++)
    {
        cin>>sArr[i];
    }
    bool dp[5001][5001]={0};
    dp[0][0]=true;
    int maxI=20;
    int maxmul=20;
    for(int j=0;j<=n;j++)
    {
        if(j>=maxI)
        {
            maxmul+=20;
            maxI+=maxmul;
        }
        int end=min(j,maxI);
        for(int i=0;i<m;i++)
        {
            int cur=sArr[i];
            for(int k=0;k<=end;k++)
            {
                if(!dp[j][k]) continue;
                int next=k+cur;
                if(next+j>n) continue;
                dp[next+j][next]=true;
            }
        }
    }
    int maxV=-1;
    for(int i=0;i<=n;i++)
    {
        if(dp[n][i]) maxV=i;
    }
    cout<<maxV<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}