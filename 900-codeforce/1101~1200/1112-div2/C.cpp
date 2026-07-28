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

struct SEGMENT
{
    int l;
    int r;
    int u;
    int v;
};

vector<SEGMENT> v;

bool isPos(int n)
{
    int idx=1;
    for(auto&seg : v)
    {
        int l=idx;
        int r=n-idx+1;
        if(seg.l<=l && l<=seg.r) continue;
        if(seg.u<=r && r<=seg.v) continue;
        idx++;
        if(idx>n) return true;
    }
    return false;
}

void program()
{
    int n;
    cin>>n;
    v.clear();
    for(int i=0;i<n;i++)
    {
        SEGMENT s1;
        cin>>s1.l>>s1.r>>s1.u>>s1.v;
        v.push_back(s1);
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(isPos(i)) res=i;
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