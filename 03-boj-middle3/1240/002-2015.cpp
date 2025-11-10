#include <iostream>
#include <map>

typedef long long ll;

using namespace std;

void makeFenwickTree(int n, ll arr[], ll fenwickTree[], int idx)
{
    ll num=arr[idx];
    while(idx<=n)
    {
        fenwickTree[idx]+=num;
        idx+=(idx & -idx);
    }
}

ll fenWicktreeSum(int idx, ll fenwickTree[])
{
    ll res=0;
    while(idx)
    {
        res+=fenwickTree[idx];
        idx-=(idx & -idx);
    }
    return res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll arr[200001];
    ll fenwickTree[200001]={0};
    map<ll,int> m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        makeFenwickTree(n,arr,fenwickTree,i);
        ll sumV=fenWicktreeSum(i,fenwickTree);
        m[sumV]++;
    }
    ll tot=0;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res+=m[k+tot];
        tot+=arr[i];
        ll sumV=fenWicktreeSum(i,fenwickTree);
        m[sumV]--;
    }
    cout<<res;
}