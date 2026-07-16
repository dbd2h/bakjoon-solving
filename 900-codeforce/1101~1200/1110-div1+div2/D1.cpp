#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 1001
 
using namespace std;
vector<pair<int,int>> graph[LEN];
vector<pair<int,int>> infoV[LEN];
vector<int> tpV[LEN];
int signArr[LEN];
bool check[LEN];
int bef[LEN];
int res[LEN];
 
void program()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
        infoV[i].clear();
        tpV[i].clear();
        signArr[i]=0;
        check[i]=0;
        res[i]=0;
        bef[i]=0;
    }
    queue<int> q;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==2) a=-1;
        if(b==c)
        {
            signArr[b]=a;
            q.push(b);
            continue;
        }
        graph[b].push_back({c,a});
        graph[c].push_back({b,a});
    }
    while(!q.empty())
    {
        int cur=q.front();
        check[cur]=1;
        q.pop();
        for(auto&p : graph[cur])
        {
            int next=p.first;
            int s=p.second;
            if(check[next]) continue;
            if(signArr[next]!=0)
            {
                if(signArr[cur]==signArr[next])
                {
                    if(signArr[cur]!=s)
                    {
                        cout<<"NO\n";
                        return;
                    }
                }
                else if(signArr[cur]==s)
                {
                    infoV[next].push_back({cur,signArr[next]});
                }
                else if(signArr[next]==s)
                {
                    infoV[cur].push_back({next,signArr[cur]});
                }   
            }
            else
            {
                if(signArr[cur]!=s)
                {
                    infoV[cur].push_back({next,signArr[cur]});
                    signArr[next]=s;
                    q.push({next});
                }
                else
                {
                    infoV[next].push_back({cur,-s});
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(signArr[i]!=0) continue;
        q.push(i);
        signArr[i]=1;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(auto&p : graph[cur])
            {
                int next=p.first;
                int s=p.second;
                if(signArr[next]!=0) continue;
                if(signArr[cur]!=s)
                {
                    infoV[cur].push_back({next,signArr[cur]});
                    signArr[next]=s;
                    q.push(next);
                }
                else
                {
                    infoV[next].push_back({cur,-s});
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int s=signArr[i];
        for(auto&p : infoV[i])
        {
            int b=p.first;
            int s2=p.second;
            if(s!=s2) continue;
            tpV[b].push_back(i);
            bef[i]++;
        }
    }
    queue<int> tpq;
    for(int i=1;i<=n;i++)
    {
        if(bef[i]) continue;
        tpq.push(i);
    }
    int num=(1e8);
    int c=0;
    while(!tpq.empty())
    {
        int cur=tpq.front();
        num--;
        c++;
        if(signArr[cur]==1) res[cur]=num;
        else if(signArr[cur]==-1) res[cur]=-num;
        tpq.pop();
        for(auto&next : tpV[cur])
        {
            bef[next]--;
            if(bef[next]==0) tpq.push(next);
        }
    }
    if(c!=n)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
    {
        cout<<res[i]<<" ";
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