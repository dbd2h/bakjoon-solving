#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 5001

using namespace std;

void program()
{
    int n;
    cin>>n;
    int arr[LEN];
    int sortArr[LEN];
    int dp[LEN];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sortArr[i]=arr[i];
        dp[i]=0;
    }
    sort(sortArr+1, sortArr+n+1);
    int mid=sortArr[(n+1)/2];
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==mid) arr[i]=0;
        else if(arr[i]>mid) arr[i]=1;
        else if(arr[i]<mid) arr[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        int midCount=0;
        int sumV=0;
        midCount+=!arr[i];
        sumV+=arr[i];
        if(arr[i]==0 && (i==1 || dp[i-1]>0)) dp[i]=dp[i-1]+1;
        for(int j=i-3;j>=0;j-=2)
        {
            sumV+=arr[j+1];
            sumV+=arr[j+2];
            midCount+=!arr[j+1];
            midCount+=!arr[j+2];
            if(j!=0 && dp[j]==0) continue;
            if(midCount>abs(sumV)) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    cout<<dp[n]<<"\n";
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