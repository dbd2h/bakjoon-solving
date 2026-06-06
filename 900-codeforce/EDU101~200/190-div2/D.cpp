#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 500003

using namespace std;

int arrA[LEN];
int nextA[LEN];
int leftEpiA[LEN];
int arrB[LEN];
int nextB[LEN];
int leftEpiB[LEN];

pair<int,int> rec(int n, int aI, int bI)
{
    if(aI==bI && aI==n+1)
    {
        return {aI,bI};
    }
    if(aI!=bI)
    {
        return {aI,bI};
    }
    else if(aI==bI)
    {
        pair<int,int> p=rec(n,nextA[aI],nextB[bI]);
        nextA[aI]=p.first;
        nextB[aI]=p.second;
        return p;
    }
}

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arrA[i];
        leftEpiA[i]=n+1;
        nextA[i]=n+1;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>arrB[i];
        leftEpiB[i]=n+1;
        nextB[i]=n+1;
    }
    leftEpiA[n+1]=leftEpiB[n+1]=n+1;
    nextA[n+1]=nextB[n+1]=n+1;
    ll res=0;
    for(int i=n;i>=1;i--)
    {
        int a=arrA[i];
        int b=arrB[i];
        leftEpiA[a]=i;
        leftEpiB[b]=i;
        nextA[i]=leftEpiA[a+1];
        nextB[i]=leftEpiB[b+1];
        pair<int,int> p=rec(n,leftEpiA[1],leftEpiB[1]);
        ll r=p.first;
        if(p.first==0 || p.first>p.second) r=p.second;
        res+=(ll)(r-i);
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