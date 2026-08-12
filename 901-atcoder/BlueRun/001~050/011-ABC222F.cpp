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
vector<pair<int,int>> graph[LEN];
int D[LEN];
ll res[LEN][2][2]={0}; // max, idx

void maxF(ll num, int idx, int next)
{
    if(res[idx][0][0]<num)
    {
        if(res[idx][0][1]==next)
        {
            res[idx][0][0]=num;
        }
        else
        {
            res[idx][1][0]=res[idx][0][0];
            res[idx][1][1]=res[idx][0][1];
            res[idx][0][0]=num;
            res[idx][0][1]=next;
        }
    }
    else if(res[idx][0][1]==next) return;
    else if(res[idx][1][0]<num)
    {
        res[idx][1][0]=num;
        res[idx][1][1]=next;
    }
}

void dfs(int cur, int p)
{
    for(auto&nextP : graph[cur])
    {
        int next=nextP.first;
        ll w=nextP.second;
        if(next==p) continue;
        maxF(D[next]+w,cur,next);
        dfs(next,cur);
        maxF(res[next][0][0]+w,cur,next);
    }
}

void dfsUp(int cur, int p)
{
    for(auto&nextP : graph[cur])
    {
        int next=nextP.first;
        ll w=nextP.second;
        if(next==p) continue;
        maxF(D[cur]+w,next,cur);
        if(res[cur][0][1]==next) maxF(res[cur][1][0]+w,next,cur);
        else maxF(res[cur][0][0]+w,next,cur);
        dfsUp(next,cur);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++) cin>>D[i];
    dfs(1,0);
    dfsUp(1,0);
    for(int i=1;i<=n;i++) cout<<res[i][0][0]<<"\n";
}