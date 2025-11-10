#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int dp[10000][10]={0};
    for(int i=0;i<n;i++)
    {
        int goal=s2[i]-'0';
        int diff=-1;
        if(i!=0) diff=s1[i]-s1[i-1];
        if(i==0)
        {
            for(int j=0;j<10;j++)
            {
                int num1=(goal-j+10)%10;
                int num2=(j-goal+10)%10;
                dp[i][j]=min(num1,num2);
            }
            continue;
        }
        int bef=(goal-diff+10)%10;
        dp[i][goal]=dp[i-1][bef];
        for(int j=1;j<10;j++)
        {
            int idx=(goal-j+10)%10;
            bef=(idx-diff+10)%10;
            int num1=(idx-goal+10)%10+dp[i-1][bef];
            int num2=1+dp[i][(idx+1)%10];
            dp[i][idx]=min(num1,num2);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<dp[n-1][s1[n-1]-'0'];
}