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

using namespace std;
vector<pair<int,int>> v;

int cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first<p2.first;
}

void program()
{
    int n;
    cin>>n;
    int k1=-1; // k1>k2
    int k2=-1;
    v.clear();
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
        if(k2==-1) k2=b;
        else if(k1==-1 && k2!=b)
        {
            if(k2>b)
            {
                k1=k2;
                k2=b;
            }
            else k1=b;
        }
    }
    ll res=0;
    int l=-1;
    int r=0;
    int minV=0;
    int maxV=0;
    while(r<n)
    {
        if(maxV-)
    }
    
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