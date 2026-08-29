#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;

using namespace std;

int main()
{
    string s;
    cin>>s;
    int dp[(2<<10)]={0};
    dp[0]=1;
    bool arr[10]={0};
    ll res=0;
    for(int i=0;i<s.size();i++)
    {
        int cur=s[i]-'0';
        arr[cur]=!arr[cur];
        int idx=0;
        for(int j=0;j<10;j++)
        {
            idx*=2;
            if(arr[j]==1) idx+=1;
        }
        res+=dp[idx];
        dp[idx]++;
    }
    cout<<res;
}