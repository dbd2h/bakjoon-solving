#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    long long dp[10001]={0};
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        long long coin;
        cin>>coin;
        for(int j=0;j<k;j++)
        {
            if(j+coin>k) break;
            dp[j+coin]+=dp[j];
        }
    }
    cout<<dp[k];
}

