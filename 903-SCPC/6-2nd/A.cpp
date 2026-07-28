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

int A[LEN];
int B[LEN];
int dist[LEN];

struct NODE
{
    int mL=-1;
    int mR=-1;
    ll maxV=0;
};

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++) cin>>B[i];
    sort(A+1,A+1+n);
    sort(B+1,B+1+n);
    for(int i=1;i<=n;i++) dist[i]=abs(A[i]-B[i]);
    ll res=0;
    ll maxDist=0;
    for(int i=1;i<=n;i++) maxDist=max(maxDist,(ll)dist[i]);
    int l=1;// [l,r], r+1->0
    ll sumV=0;
    NODE n1;
    for(int r=1;r<n;r++)
    {
        ll cur=dist[r+1];
        sumV+=(dist[r]-abs(A[r]-B[r+1]));

        if(sumV<0)
        {
            l=r+1;
            sumV=0;
            continue;
        }
        if(n1.maxV<sumV+cur)
        {
            n1.mL=l;
            n1.mR=r;
            n1.maxV=sumV+cur;
        }
    }
    NODE n2;
    sumV=0;
    int r=n;
    for(l=n;l>1;l--)
    {
        ll cur=dist[l-1];
        sumV+=(dist[l]-abs(A[l]-B[l-1]));
        if(sumV<0)
        {
            r=l-1;
            sumV=0;
            continue;
        }
        if(n2.maxV<sumV+cur)
        {
            n2.mL=l;
            n2.mR=r;
            n2.maxV=sumV+cur;
        }
    }
    ll num1=n1.maxV;
    ll num2=n2.maxV;
    ll tot=0;
    for(int i=1;i<=n;i++) tot+=dist[i];
    res=tot-maxDist;
    if(num1>num2)
    {
        tot-=num1;
    }
    else
    {
        if(num2==0)
        {
            tot-=maxDist;
        }
        else tot-=num2;
    }
    res=min(res,tot);
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
        cout<<"Case #"<<i<<endl;
        program();
    }
}