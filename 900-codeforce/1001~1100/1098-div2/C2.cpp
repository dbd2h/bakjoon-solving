#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

using namespace std;

bool bit[10]={0};
ll res;
ll maxV;
ll minV;

void aMaker(ll a, vector<int> &v)
{
    if(a==0) return;
    aMaker(a/10,v);
    v.push_back(a%10);
}

void resMaker(vector<int> &v, ll a, int idx, ll sumV)
{
    int len=v.size();
    if(idx==len)
    {
        res=min(abs(sumV-a),res);
        return;
    }
    int cur=v[idx];
    if(bit[cur])
    {
        resMaker(v,a,idx+1,sumV*10+(ll)cur);
    }
    for(int i=cur-1;i>=0;i--)
    {
        if(bit[i]==0 && !(idx==0 && i==0 && len!=1)) continue;
        ll num=sumV;
        int idx2=idx+1;
        num=num*(ll)10+(ll)i;
        while(idx2<len)
        {
            num=num*(ll)10+maxV;
            idx2++;
        }
        res=min(abs(num-a),res);
        break;
    }
    for(int i=cur+1;i<=9;i++)
    {
        if(bit[i]==0) continue;
        ll num=sumV;
        int idx2=idx+1;
        num=num*(ll)10+(ll)i;
        while(idx2<len)
        {
            num=num*(ll)10+minV;
            idx2++;
        }
        res=min(abs(num-a),res);
        break;
    }
}

void program()
{
    ll a;
    int n;
    cin>>a>>n;
    for(int i=0;i<=9;i++) bit[i]=0;
    maxV=0;
    minV=9;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        bit[num]=1;
        if(num>maxV) maxV=num;
        if(num<minV) minV=num;
    }
    if(a==0)
    {
        cout<<minV<<"\n";
        return;
    }
    vector<int> v;
    aMaker(a,v);
    res=1e17;
    if(bit[1])
    {
        ll num=1;
        int idx=0;
        while(idx<v.size())
        {
            num=num*10+minV;
            idx++;
        }
        res=min(res,abs(num-a));
    }
    resMaker(v,a,0,0);
    cout<<res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}