#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<pair<int,int>,int>> v;
vector<int> graph[1001];

int compare(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2)
{
    return p1.second<p2.second;
}

void dfs(bool check[], int parent, int cur, int b, bool *isC)
{
    if(parent==0)
    {
        check[b]=1;
        dfs(check,cur,b,b,isC);
    }
    for(int i=0;i<graph[cur].size();i++)
    {
        int next=graph[cur][i];
        if(next==parent) continue;
        if(check[next])
        {
            (*isC) = true;
            return;
        }
        check[next]=1;
        dfs(check,cur,next,b,isC);
        if(*isC) return;
    }
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({{a,b},c});
    }
    sort(v.begin(),v.end(),compare);
    int res=0;
    int count=0;
    for(int i=0;i<m;i++)
    {
        pair<pair<int,int>,int> p=v[i];
        int a=p.first.first;
        int b=p.first.second;
        int c=p.second;
        if(a==b) continue;
        bool check[1001]={0};
        check[a]=1;
        bool isC=false;
        dfs(check,0,a,b,&isC);
        if(isC) continue;
        graph[a].push_back(b);
        graph[b].push_back(a);
        count++;
        res+=c;
        if(count==(n-1)) break;
    }
    cout<<res;
}