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
    
    while(len>1)
    {
        if(k-sumV>(len-1)*2)
        {
            v.push_back(len);
            sumV+=(len-1)*2;
            len-=2;
        }
        else
        {
            v.push_back(sumV/2+1);
            sumV=k;
            break;
        }
    }
    if(sumV<k)
    {
        cout<<-1<<"\n";
        return;
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