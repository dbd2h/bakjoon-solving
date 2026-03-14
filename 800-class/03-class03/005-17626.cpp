#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int dp[50001];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int mulV=j*j;
            if(i<mulV) break;
            if(j==1)
            {
                dp[i]=dp[i-mulV]+1;
            } 
            else if(dp[i]>dp[i-mulV]+1)
            {
                dp[i]= dp[i-mulV]+1;
            } 
        }
    }
    cout<<dp[n];
}