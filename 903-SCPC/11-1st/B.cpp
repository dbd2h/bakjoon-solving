#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 100001

using namespace std;

void program()
{
    int n,l;
    cin>>n>>l;
    int arr[LEN];
    int mid=l/2;
    int idx=-1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(idx==-1 && arr[i]>mid) idx=i;
    } 
    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=mid) res+=arr[i]*2LL;
        else res+=(l-arr[i])*2LL;
    }
    if(idx==-1)
    {
        cout<<res<<"\n";
        return;
    }
    else if(idx==0)
    {
        res-=(l-arr[0])*2LL;
        res+=l;
        cout<<res<<"\n";
        return;
    }
    res=min(res-(l-arr[idx])*2LL+l,res-arr[idx-1]*2LL+l);
    cout<<res<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<"\n";
        program();
    }
}