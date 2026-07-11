#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 200001

using namespace std;

ll arr[LEN];

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    pair<ll,ll> p1,p2;
    p1={0,arr[1]};
    p2={0,arr[1]};
    int idx1=1;
    int idx2=1;
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(i==n)
        {
            ll res;
            res=max(p1.first+abs(arr[i]-p1.second),p2.first+abs(arr[i]-p2.second));
            cout<<res<<endl;
            break;
        }
        if((p2.second-arr[i])*(arr[i]-arr[i+1])>=0) continue;
        ll sum1=max(p1.first+abs(arr[i]-p1.second),p2.first+abs(arr[i]-p2.second));
        ll sum2=p2.first+abs(arr[i-1]-p2.second);
        if(idx1<=i-1) sum2=max(sum2,p1.first+abs(arr[i-1]-p1.second));
        else sum2=max(sum2,p1.first);
        p1={sum1,arr[i+1]};
        idx1=i+1;
        p2={sum2,arr[i]};
        idx2=i;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}