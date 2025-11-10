#include <iostream>
typedef long long ll;

using namespace std;

int main()
{
    ll dp[31][31]={0};
    for(int i=0;i<=30;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=30;i++)
    {
        for(int j=1;j<=30;j++)
        {
            if(i<j) break;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    int num;
    cin>>num;
    while(num)
    {
        cout<<dp[num][num]<<"\n";
        cin>>num;
    }
}