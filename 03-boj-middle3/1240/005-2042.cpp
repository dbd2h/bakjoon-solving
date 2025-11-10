#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

void makeFenwickTree(int n, ll arr[], ll fenwickTree[], int idx)
{
    ll num=arr[idx];
    while(idx<=n)
    {
        fenwickTree[idx]+=num;
        idx+=(idx&-idx);
    }
}

void updateFenwickTree(int n, ll arr[], ll fenwickTree[], int idx, ll num)
{
    ll befN=arr[idx];
    while(idx<=n)
    {
        fenwickTree[idx]-=befN;
        fenwickTree[idx]+=num;
        idx+=(idx&-idx);
    }
}

ll fenwickTreeFind(ll fenwickTree[], int idx)
{
    ll res=0;
    while(idx)
    {
        res+=fenwickTree[idx];
        idx-=(idx&-idx);
    }
    return res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    ll arr[1000001];
    ll fenwickTree[1000001]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        makeFenwickTree(n,arr,fenwickTree,i);
    }
    for(int i=0;i<m+k;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            updateFenwickTree(n,arr,fenwickTree,b,c);
            arr[b]=c;
        }
        else if(a==2)
        {
            cout<<fenwickTreeFind(fenwickTree,c)-fenwickTreeFind(fenwickTree,b-1)<<"\n";
        }
    }
}