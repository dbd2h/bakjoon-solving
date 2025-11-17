#include <iostream>

typedef long long ll;
#define LEN (ll)1'000'001


using namespace std;

int main()
{
    int n;
    cin>>n;
    ll rem=1'000'000'000;
    ll dp[LEN];
    dp[1]=0;
    dp[2]=1;
    for(ll i=3;i<=n;i++)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
        dp[i]%=rem;
    }
    cout<<dp[n];
}