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
#define LEN 1001

using namespace std;

ll arr[LEN];

int main()
{
    int n;
    ll p;
    cin>>n>>p;
    ll tot=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        tot+=arr[i];
    } 
    ll l=0;
    ll r=0;
    ll sumV=0;
    r=p/tot*n;
    sumV=p/tot*tot;
    ll res=-1;
    int resI=-1;
    while(l<n)
    {
        if(sumV<p)
        {
            int idx=r%n;
            sumV+=arr[idx];
            r++;
        }
        else
        {
            if(res==-1 || res>(r-l))
            {
                res=r-l;
                resI=l+1;
            } 
            sumV-=arr[l];
            l++;
        }
    }
    cout<<resI<<" "<<res;
}