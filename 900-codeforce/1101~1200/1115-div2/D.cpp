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
#define LEN 200001

using namespace std;

ll arr[LEN];
ll dist[LEN];

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++) dist[i]=arr[i+1]-arr[i];
    int r=1;
    while(r<n)
    {
        int l=r;
        while(r<n && (dist[l]&1) == (dist[r]&1)) r++;
        sort(dist+l, dist+r);
    }
    for(int i=1;i<n;i++)
    {
        arr[i+1]=arr[i]+dist[i];
    }
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<"\n"; 
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