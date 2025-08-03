#include <iostream>
#define LEN 2501
#define DIV 1'000'000'007

using namespace std;

int main()
{
    int t;
    cin>>t;
    int dp[LEN][LEN]={0};
    for(int i=1;i<LEN;i++)
    {
        dp[0][i]=1;
    }
    for(int i=1;i<LEN;i++)
    {
        for(int j=i;j<LEN;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            if(dp[i][j]>=DIV) dp[i][j]%=DIV;
        }
    }
    for(int i=0;i<t;i++)
    {
        int num;
        cin>>num;
        if(num%2==1)
        {
            cout<<0<<"\n";
            continue;
        }
        cout<<dp[num/2][num/2]<<"\n";
    }
}