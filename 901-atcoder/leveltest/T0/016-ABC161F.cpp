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
#define LEN (int)(1e6+1)


using namespace std;

vector<ll> primeV;
vector<pair<ll,ll>> divV;
bool arr[LEN]={0};

bool isPos(ll n, ll mul)
{
    while(n>1)
    {
        if(n%mul==0) n/=mul;
        else
        {
            n=n%mul;
            break;
        } 
    }
    if(n==1) return true;
    else return false;
}

void dfs(ll n, int len, int idx, ll mul, ll *res)
{
    if(len==idx)
    {
        if(mul==1) return;
        if(isPos(n,mul)) (*res)++;
        return;
    }
    ll cur=divV[idx].first;
    ll c=divV[idx].second;
    ll next=1;
    dfs(n,len,idx+1,mul,res);
    for(int i=1;i<=c;i++)
    {
        next*=cur;
        dfs(n,len,idx+1,mul*next,res);
    }
}

int main()
{
    for(int i=2;i<LEN;i++)
    {
        if(arr[i]) continue;
        primeV.push_back(i);
        for(int j=2;i*j<LEN;j++) arr[i*j]=1;
    }
    ll n;
    cin>>n;
    ll copyN=n-1;
    ll res=1;
    for(auto&num : primeV)
    {
        int c=1;
        while(copyN%num==0)
        {
            copyN/=num;
            c++;
        }
        res*=c;
    }
    if(copyN>1) res*=2;
    res--;
    copyN=n;
    for(auto&num : primeV)
    {
        int c=0;
        while(copyN%num==0)
        {
            copyN/=num;
            c++;
        } 
        if(c==0) continue;
        divV.push_back({num,c});
    }
    if(copyN>1) divV.push_back({copyN,1});
    int len=divV.size();
    dfs(n,len,0,1,&res);
    cout<<res;
}   