#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define LEN 501

#define INF 1e9

using namespace std;

int lmatch[LEN];
int rmatch[LEN];
int dist[LEN];

bool bfs(vector<int> graph[LEN], int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(lmatch[i]==0)
        {
            q.push(i);
            dist[i]=0;
        }
        else dist[i]=INF;
    }
    bool found=false;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto& r : graph[cur])
        {
            int l=rmatch[r];
            if(l==0) found=true;
            else if(dist[l]==INF)
            {
                q.push(l);
                dist[l]=dist[cur]+1;
            }
        }
    }
    return found;
}

bool dfs(vector<int> graph[LEN], int cur)
{
    for(auto& r : graph[cur])
    {
        int l=rmatch[r];
        if(l==0 || (dist[l]==dist[cur]+1 && dfs(graph,l)))
        {
            lmatch[cur]=r;
            rmatch[r]=cur;
            return true;
        }
    }
    return false;
}

void problem()
{
    int n;
    cin>>n;
    int male=0;
    int female=0;
    vector<pair<int,pair<string,string>>> maleV;
    vector<pair<int,pair<string,string>>> femaleV;
    vector<int> graph[LEN];
    for(int i=0;i<n;i++)
    {
        int h;
        char gender;
        string music,sport;
        cin>>h>>gender>>music>>sport;
        if(gender=='M')
        {
            male++;
            maleV.push_back({h,{music,sport}});
        }
        else
        {
            female++;
            femaleV.push_back({h,{music,sport}});
        }
    }
    int mLen=maleV.size();
    int fLen=femaleV.size();
    for(int i=0;i<mLen;i++)
    {
        for(int j=0;j<fLen;j++)
        {
            pair<int,pair<string,string>> p1, p2;
            p1=maleV[i];
            p2=femaleV[j];
            if(abs(p1.first-p2.first)>40) continue;
            if(p1.second.first!=p2.second.first) continue;
            if(p1.second.second==p2.second.second) continue;
            graph[i+1].push_back(j+1);
        }
    }
    int res=0;
    for(int i=1;i<=male;i++) lmatch[i]=0;
    for(int i=1;i<=female;i++) rmatch[i]=0;
    while(bfs(graph,male))
    {
        for(int i=1;i<=male;i++)
        {
            if(lmatch[i]==0 && dfs(graph,i)) res++;
        }
    }

    cout<<n-res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}