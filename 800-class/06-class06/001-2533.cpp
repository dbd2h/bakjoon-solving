#include <iostream>
#include <vector>

#define LEN 1000001

using namespace std;

void treeInit(vector<int> graph[LEN], int parentArr[], int childArr[], int cur, int p)
{
    parentArr[cur]=p;
    for(auto &next : graph[cur])
    {
        if(parentArr[cur]==next) continue;
        childArr[cur]++;
        treeInit(graph,parentArr,childArr,next,cur);
    }
}

void dfs(vector<int> graph[LEN], int parentArr[], int childArr[], int cur, int *res)
{
    for(auto &next : graph[cur])
    {
        if(parentArr[cur]==next) continue;
        dfs(graph,parentArr,childArr,next,res);
    }
    if(childArr[cur]==0) return;
    (*res)++;
    int p=parentArr[cur];
    if(p==-1) return;
    childArr[p]--;
}

int main()
{
    int n;
    cin>>n;
    int parentArr[LEN];
    int childArr[LEN]={0};
    vector<int> graph[LEN];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    treeInit(graph,parentArr,childArr,1,-1);
    int res=0;
    dfs(graph,parentArr,childArr,1,&res);
    cout<<res;
}