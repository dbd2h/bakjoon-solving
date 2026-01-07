#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int> graph[10001], bool check[], int numArr[], int low[], int parentArr[], int *cur, int parent, int node, vector<int> &resultV, int root)
{
    check[node]=1;
    numArr[node]=*cur;
    low[node]=*cur;
    parentArr[node]=parent;
    (*cur)++;
    int c=0;
    for(auto&next : graph[node])
    {
        if(check[next]) continue;
        if(node==root) c++;
        dfs(graph,check,numArr,low,parentArr,cur,node,next,resultV,root);
    }
    bool isDiscon=false;
    if(node==root)
    {
        if(c>=2)
        {
            resultV.push_back(root);
        }
        return;
    }
    for(auto &next : graph[node])
    {
        if(low[node]>low[next])low[node]=low[next];
        if(node!=parentArr[next]) continue;
        if(low[next]>=numArr[node])
        {
            isDiscon=true;
        }
    }
    if(isDiscon) resultV.push_back(node);
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> graph[10001];
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool check[10001]={0};
    int numArr[10001];
    int low[10001];
    int parentArr[10001];
    vector<int> resultV;
    int cur=1;
    for(int i=1;i<=v;i++)
    {
        if(check[i]) continue;
        dfs(graph,check,numArr,low,parentArr,&cur,0,i,resultV,i);
    }
    sort(resultV.begin(),resultV.end());
    int len=resultV.size();
    cout<<len<<"\n";
    for(int i=0;i<len;i++)
    {
        cout<<resultV[i]<<" ";
    }
}