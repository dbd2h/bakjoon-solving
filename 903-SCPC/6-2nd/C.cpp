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

int arr[LEN];
ll sumArr[LEN];
priority_queue<ll> pqHi,pqHiRem;
priority_queue<ll,vector<ll>,greater<ll>> pqLo,pqLoRem;

void pqPop()
{
    while(!pqHi.empty() && !pqHiRem.empty())
    {
        if(pqHiRem.top()!=pqHi.top()) break;
        pqHiRem.pop();
        pqHi.pop();
    }
    while(!pqLo.empty() && !pqLoRem.empty())
    {
        if(pqLoRem.top()!=pqLo.top()) break;
        pqLoRem.pop();
        pqLo.pop();
    }
}

void program()
{
    int n,k,q;
    cin>>n>>k>>q;
    pqHi=priority_queue<ll>();
    pqHiRem=priority_queue<ll>();
    pqLo=priority_queue<ll,vector<ll>,greater<ll>>();
    pqLoRem=priority_queue<ll,vector<ll>,greater<ll>>();
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll sumV=0;
    for(int i=1;i<=k;i++) sumV+=arr[i];
    sumArr[1]=sumV;
    for(int i=k+1;i<=n;i++)
    {
        sumV-=arr[i-k];
        sumV+=arr[i];
        sumArr[i-k+1]=sumV;
    }
    for(int i=1;i<=n-k+1;i++) pqLo.push(sumArr[i]);
    for(int i=1;i<=(n-k+1)/2;i++)
    {
        pqHi.push(pqLo.top());
        pqLo.pop();
    }
    cout<<pqLo.top()<<" ";
    while(q--)
    {
        int idx;
        ll num;
        cin>>idx>>num;
        ll oriNum=arr[idx];
        arr[idx]=num;
        int l=0;
        int r=0;
        vector<ll> v;
        for(int i=max(1,idx-k+1);i<=min(idx,n-k+1);i++)
        {
            int outNum=sumArr[i];
            if(!pqHi.empty() && pqHi.top()>=outNum)
            {
                pqHiRem.push(outNum);
                l++;
            } 
            else
            {
                pqLoRem.push(outNum);
                r++;
            }
            sumArr[i]=outNum-oriNum+num;
            v.push_back(sumArr[i]);
            pqPop();
        }
        while(l<k && !pqHi.empty())
        {
            v.push_back(pqHi.top());
            pqHi.pop();
            pqPop();
            l++;
        }
        while(r<k && !pqLo.empty())
        {
            v.push_back(pqLo.top());
            pqLo.pop();
            pqPop();
            r++;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<l;i++)
        {
            pqHi.push(v[i]);
        }
        for(int i=l;i<l+r;i++)
        {
            pqLo.push(v[i]);
        }
        cout<<pqLo.top()<<" ";
    }
    cout<<"\n";
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