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
#define LEN 5001

using namespace std;

int arr[LEN];

int cmp(int n1, int n2)
{
    return n1>n2;
}

int dp[LEN]={0};

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,cmp);
    dp[0]=1;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int cur=arr[i];
        for(int j=k-1;j>=0;j--)
        {
            if(dp[j]==0) continue;
            if(j+cur>=k) res=-1;
            else dp[j+cur]=1;
        }
        res++;
    }
    cout<<res;
}