#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int n;
    cin>>n;
    int dp[100001]={0};
    int rem=10'000'003;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        for(int j=1;j<=100000;j++)
        {
            if(dp[j]==0) continue;
            int gcdV=gcd(num,j);
            dp[gcdV]+=dp[j];
            dp[gcdV]%=rem;
        }
        dp[num]++;
        dp[num]%=rem;
    }
    cout<<dp[1];
}