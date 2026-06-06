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

ll cmp(ll n1, ll n2)
{
    return n1>n2;
}

void program()
{
    int n,m;
    cin>>n>>m;
    ll oddArr[LEN];
    ll evenArr[LEN];
    int oLen=0;
    int eLen=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            cin>>oddArr[(i+1)/2];
            oLen++;
        } 
        else
        {
            cin>>evenArr[(i+1)/2];
            eLen++;
        } 
    }
    sort(oddArr+1,oddArr+oLen+1,cmp);
    sort(evenArr+1,evenArr+eLen+1,cmp);
    int oIdx=1;
    int eIdx=1;
    for(int i=0;i<m;i++)
    {
        int idx;
        cin>>idx;
        if(idx%2==1)
        {
            if(oIdx==1) oIdx++;
            else if(oddArr[oIdx]>0) oIdx++;
        }
        else
        {
            if(eIdx==1) eIdx++;
            else if(evenArr[eIdx]>0) eIdx++;
        }
    }
    ll res=0;
    for(int i=oIdx;i<=oLen;i++)
    {
        res+=oddArr[i];
    }
    for(int i=eIdx;i<=eLen;i++)
    {
        res+=evenArr[i];
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