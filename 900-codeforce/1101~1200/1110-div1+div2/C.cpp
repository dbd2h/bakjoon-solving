#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 400001

using namespace std;

bool check[LEN];

void program()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++) check[i]=0;
    int num=n^k;
    int bit=1;
    vector<int> v;
    while(num)
    {
        if(num%2==1)
        {
            v.push_back(bit);
            check[bit]=1;
        } 
        bit*=2;
        if(bit>=LEN)
        {
            cout<<"NO\n";
            return;
        }
        num/=2;
    }
    int len=v.size();
    if(len!=0 && v[len-1]>=n)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=1;i<n;i++)
    {
        if(check[i]) continue;
        cout<<i<<" ";
    }
    cout<<0<<" ";
    for(int i=0;i<len;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
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