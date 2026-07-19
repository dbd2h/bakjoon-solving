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
ll resArr[LEN];

void program()
{
    ll n,k;
    cin>>n>>k;
    if(k%2==1)
    {
        cout<<-1<<"\n";
        return;
    }
    ll sumV=(n-1)*2;
    if(k<sumV)
    {
        cout<<-1<<"\n";
        return;
    }
    vector<ll> v;
    v.push_back(n);
    ll len=n-2;
    
    while(len>1 && sumV<k)
    {
        if(k-sumV>=(len-1)*2)
        {
            v.push_back(len);
            sumV+=(len-1)*2;
            len-=2;
        }
        else
        {
            v.push_back((k-sumV)/2+1);
            sumV=k;
            break;
        }
    }
    if(sumV<k)
    {
        cout<<-1<<"\n";
        return;
    }
    ll lIdx=1;
    ll rIdx=n;
    ll lNum=1;
    ll rNum=n;
    bool isFlipped=false;
    ll idx=0;
    while(lIdx<=rIdx)
    {
        ll c=v[idx];
        if(v.size()-1>idx) c-=v[idx+1];
        if(!isFlipped)
        {
            for(ll i=lIdx;i<lIdx+c-1;i++)
            {
                resArr[i]=lNum;
                lNum++;
            }
            lIdx+=c-1;
            resArr[rIdx]=rNum;
            rNum--;
            rIdx--;
        }
        else
        {
            for(ll i=lIdx;i<lIdx+c-1;i++)
            {
                resArr[i]=rNum;
                rNum--;
            }
            lIdx+=c-1;
            resArr[rIdx]=lNum;
            lNum++;
            rIdx--;
        }
        idx++;
        isFlipped=!isFlipped;
    }
    for(ll i=1;i<n;i++)
    {
        cout<<resArr[i]<<" "<<resArr[i+1]<<"\n";
    }
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