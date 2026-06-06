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

ll cmp(ll a, ll b)
{
    return a>b;
}

void program()
{
    int n;
    cin>>n;
    ll arr[LEN];
    ll sumV=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sumV+=arr[i];
    }
    if(sumV<3)
    {
        cout<<0<<"\n";
        return;
    }
    sort(arr,arr+n,cmp);
    ll res=0;
    if(n==1)
    {
        cout<<arr[0]<<"\n";
        return;
    } 
    ll bet=0;
    if(arr[1]==1)
    {
        
        for(int i=0;i<n;i++)
        {
            
            if(arr[i]==1)
            {
                if(i==0)
                {
                    cout<<0<<"\n";
                    return;
                }
                if(bet==0) break;
                bet--;
                res++;
                continue;
            }
            res+=arr[i];
            bet+=(arr[i]/2);
        }
        cout<<res<<"\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            if(bet==0) break;
            bet--;
            res++;
            continue;
        }
        res+=arr[i];
        bet+=((arr[i]-2)/2);
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