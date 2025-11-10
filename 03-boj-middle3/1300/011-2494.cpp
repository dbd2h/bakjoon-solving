#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int dp[10000][10];
    int res[10000][10]={0};
    for(int i=0;i<n;i++)
    {
        int goal=s2[i]-'0';
        int diff=-1;
        if(i!=0)
        {
            diff=s1[i]-s1[i-1];
        }
        if(i==0)
        {
            for(int j=0;j<10;j++)
            {
                int idx=(goal+j)%10;
                int num1=(idx-goal+10)%10;
                int num2=(goal-idx+10)%10;
                if(num1>num2)
                {
                    dp[i][idx]=num2;
                    res[i][idx]=num2;
                }
                else
                {
                    dp[i][idx]=num1;
                    res[i][idx]=-num1;
                }
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
            int num2=dp[i][(idx+1)%10]+1;
            if(num1>num2)
            {
                dp[i][idx]=num2;
                res[i][idx]=res[i][(idx+1)%10]+1;
            }
            else
            {
                dp[i][idx]=num1;
                res[i][idx]=(goal-idx+10)%10-10;
            }
        }
    }
    cout<<dp[n-1][s1[n-1]-'0']<<"\n";
    int leftTot=0;
    for(int i=n-1;i>=0;i--)
    {
        int cur=s1[i]-'0';
        cur+=leftTot;
        cur%=10;
        cout<<n-i<<" "<<res[i][cur]<<"\n";
        if(res[i][cur]>0) leftTot+=res[i][cur];
    }
}