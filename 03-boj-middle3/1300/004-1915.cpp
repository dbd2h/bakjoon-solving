#include <iostream>
#include <string>
#define LEN 1000

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    bool arr[LEN][LEN];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            arr[i][j]=s[j]-'0';
        }
    }
    int dp[LEN][LEN]={0};
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i][0])
        {
            dp[i][0]=1;
            res=1;
        } 
    }
    for(int i=0;i<m;i++)
    {
        if(arr[0][i])
        {
            dp[0][i]=1;
            res=1;
        } 
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==0) continue;
            int minV=dp[i-1][j-1];
            if(dp[i][j-1]<minV) minV=dp[i][j-1];
            if(dp[i-1][j]<minV) minV=dp[i-1][j];
            dp[i][j]=minV+1;
            if(dp[i][j]>res) res=dp[i][j];
        }
    }
    cout<<res*res;
}