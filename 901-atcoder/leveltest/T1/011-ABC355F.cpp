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

int parent[LEN][10];

int findP(int a, int idx)
{
    if(parent[a][idx]==a) return a;
    parent[a][idx]=findP(parent[a][idx],idx);
    return parent[a][idx];
}

void unionF(int a, int b, int idx)
{
    if(a>b)
    {
        int c=a;
        a=b;
        b=c;
    }
    parent[b][idx]=a;
    return;
}

int main()
{
    int n,q;
    cin>>n>>q;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=9;j++) parent[i][j]=i;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        res+=c;
        for(int j=c;j<10;j++)
        {
            int ap=findP(a,j);
            int bp=findP(b,j);
            unionF(ap,bp,j);
        } 
    }
    for(int i=0;i<q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        bool isF=false;
        for(int i=1;i<c;i++)
        {
            int ap=findP(a,i);
            int bp=findP(b,i);
            if(ap==bp)
            {
                isF=true;
                break;
            } 
        }
        if(isF)
        {
            cout<<res<<"\n";
            continue;
        }
        for(int i=c;i<10;i++)
        {
            int ap=findP(a,i);
            int bp=findP(b,i);
            if(ap==bp) break;
            unionF(ap,bp,i);
            res--;
        }
        cout<<res<<"\n";
    }
}