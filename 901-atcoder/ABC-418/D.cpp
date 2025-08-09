#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dp[200000][2]={0};
    long long res=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            if(i==0)
            {
                dp[i][0]++;
            }
            else
            {
                dp[i][1]=dp[i-1][0];
                dp[i][0]=dp[i-1][1]+1;
            }
            
        }
        else if(s[i]=='1')
        {
            if(i==0)
            {
                dp[i][1]++;
            }
            else
            {
                dp[i][1]=dp[i-1][1]+1;
                dp[i][0]=dp[i-1][0];
            }
            
            
        }
        
        res+=(long long) dp[i][1];
    }
    cout<<res;
}