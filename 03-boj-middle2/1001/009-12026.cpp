#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dp[1000]={0};
    for(int i=1;i<n;i++)
    {
        dp[i]=-1;
    }
    for(int i=1;i<n;i++)
    {
        char cur=s[i];
        char bef;
        if(cur=='B') bef='J';
        else if(cur=='O') bef='B';
        else if(cur=='J') bef='O';
        int minV=-1;
        for(int j=0;j<i;j++)
        {
            if(bef!=s[j] || dp[j]==-1) continue;
            if(minV==-1 || (i-j)*(i-j)+dp[j]<minV) minV=(i-j)*(i-j)+dp[j];
        }
        dp[i]=minV;
    }
    cout<<dp[n-1];
}