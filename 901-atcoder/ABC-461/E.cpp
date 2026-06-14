#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#define LEN 300002
typedef long long ll;

using namespace std;

ll bit[2][LEN]={0};
ll last[2][LEN]={0}; // t==0: row black, t==1: col white

ll query(int t, int r)
{
    ll ret=0;
    while(r)
    {
        ret+=bit[t][r];
        r-=r&-r;
    }
    return ret;
}

void update(int t, int r, ll num, int n)
{
    while(r<=n)
    {
        bit[t][r]+=num;
        r+=r&-r;
    }
}

int main()
{
    int n,q;
    cin>>n>>q;
    ll res=0;
    for(int i=1;i<=q;i++)
    {
        int t,num;
        cin>>t>>num;
        t-=1;
        if(t==0 && last[t][num]==0)
        {
            res+=(ll)n;
        }
        else
        {
            int type=query(1-t,i)-query(1-t,last[t][num]);
            res+=(t==0 ? type : -type);
            if(last[t][num]) update(t,last[t][num],-1,q);
        }
        update(t,i,1,q);
        last[t][num]=i;
        cout<<res<<"\n";
    }
    
}