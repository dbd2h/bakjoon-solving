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

set<int> pSet[LEN], mSet[LEN];
int signArr[LEN];
bool check[LEN];

void program()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        pSet[i].clear();
        mSet[i].clear();
        signArr[i]=0;
        check[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            pSet[b].insert(c);
            pSet[c].insert(b);
        }
        else if(a==2)
        {
            mSet[b].insert(c);
            mSet[c].insert(b);
        }
    }
    queue<int> q;
    int num=(1e8);
    int c=0;
    int res[LEN];
    for(int i=1;i<=n;i++)
    {
        if(pSet[i].empty() || mSet[i].empty())
        {
            q.push(i);
            check[i]=1;
        }
    }
    while(!q.empty())
    {
        int cur=q.front();
        c++;
        q.pop();
        if(pSet[cur].empty())
        {
            res[cur]=-num;
        }
        else if(mSet[cur].empty())
        {
            res[cur]=num;
        }
        num--;
        for(auto&next : pSet[cur])
        {
            if(check[next]) continue;
            if(next!=cur) pSet[next].erase(cur);
            if(pSet[next].empty())
            {
                q.push(next);
                check[next]=1;
            } 
        }
        for(auto&next : mSet[cur])
        {
            if(check[next]) continue;
            if(next!=cur) mSet[next].erase(cur);
            if(mSet[next].empty())
            {
                q.push(next);
                check[next]=1;
            } 
        }
    }
    if(c!=n)
    {
        cout<<"NO\n";
        return;
    } 
    cout<<"YES\n";
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
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