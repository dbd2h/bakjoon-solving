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

ll fenwickTreeSum(int idx, ll fenwickTree[])
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
    ll n,m;
    cin>>n>>m;
    ll arr[1000001];
    ll fenwickTree[1000001]={0};
    map<ll,int> remainM;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        makeFenwickTree(n,arr,fenwickTree,i);
        ll sumV=fenwickTreeSum(i,fenwickTree);
        remainM[sumV%m]++;
    }

    ll res=0;
    ll tot=0;
    for(int i=1;i<=n;i++)
    {
        res+=remainM[((tot%m)+m)%m];
        tot+=arr[i];
        remainM[tot%m]--;
    }
    cout<<res;
}