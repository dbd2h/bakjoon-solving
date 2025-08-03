#include <iostream>

using namespace std;

int main()
{
    int n,s,m;
    cin>>n>>s>>m;
    bool dp[51][1001]={0};
    dp[0][s]=true;
    for(int i=0;i<n;i++)
    {
        int v;
        cin>>v;
        for(int j=0;j<=m;j++)
        {
            if(!dp[i][j]) continue;
            if(j-v>=0) dp[i+1][j-v]=true;
            if(j+v<=m) dp[i+1][j+v]=true;
        }
    }
    int maxV=-1;
    for(int j=m;j>=0;j--)
    {
        if(dp[n][j])
        {
            maxV=j;
            break;
        }
    }
    cout<<maxV;
}