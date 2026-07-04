#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 501

using namespace std;

int dp[LEN][LEN][LEN]; // idx, f개수, 연산값

void program()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=n;k++) dp[i][j][k]=1e9;
        }
    }
    dp[0][0][0]=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        char cur=s[i];
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<=i;k++)
            {
                if(dp[i][j][k]==(int)(1e9)) continue;
                if(cur!='F')
                {
                    int next=k-1;
                    if(next<0) next=0;
                    dp[i+1][j][next]=min(dp[i+1][j][next],dp[i][j][k]);
                    if(res<(j-dp[i+1][j][next])) res=(j-dp[i+1][j][next]);
                }
                if(cur!='T')
                {
                    int num=dp[i][j][k];
                    if(k==dp[i][j][k]) num=k+1;
                    dp[i+1][j+1][k+1]=min(dp[i+1][j+1][k+1],num);
                    if(res<(j+1-dp[i+1][j+1][k+1])) res=(j+1-dp[i+1][j+1][k+1]);
                }
            }
        }
    }
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}