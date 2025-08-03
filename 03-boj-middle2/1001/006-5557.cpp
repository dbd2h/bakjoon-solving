#include <iostream>

using namespace std;

int main()
{
    long long dp[101][21]={0};
    int n;
    cin>>n;
    dp[0][0]=1;
    for(int i=0;i<n-1;i++)
    {
        int num;
        cin>>num;
        for(int j=0;j<=20;j++)
        {
            
            if(!dp[i][j]) continue;
            if(i==0 && num==0)
            {
                dp[i+1][j]+=dp[i][j];
                continue;
            }
            if(j+num<=20) dp[i+1][j+num]+=dp[i][j];
            if(j-num>=0) dp[i+1][j-num]+=dp[i][j];
        }
    }
    int goal;
    cin>>goal;
    cout<<dp[n-1][goal];
}