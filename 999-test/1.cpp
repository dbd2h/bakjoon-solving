#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define LEN 10001

using namespace std;

vector<int> graph[LEN];
int tin[LEN]={0};
int low[LEN];
bool inStack[LEN]={0};
stack<int> st;
int timer=0;
int sccArr[LEN];
int sccI=0;
vector<int> resV[LEN];

void dfs(int cur)
{
    st.push(cur);
    inStack[cur]=1;
    timer++;
    tin[cur]=timer;
    low[cur]=timer;
    for(auto& next : graph[cur])
    {
        if(tin[next]==0)
        {
            dfs(next);
            low[cur]=min(low[cur],low[next]);
        }
        else if(inStack[next])
        {
            low[cur]=min(low[cur],tin[next]);
        }
    }
    if(low[cur]==tin[cur])
    {
        sccI++;
        while(st.top()!=cur)
        {
            sccArr[st.top()]=sccI;
            inStack[st.top()]=0;
            st.pop();
        }
        sccArr[st.top()]=sccI;
        inStack[st.top()]=0;
        st.pop();
    }
}

int cmp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first<p2.first;
}

int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1;i<=v;i++)
    {
        if(tin[i]!=0) continue;
        dfs(i);
    }
    int len=0;
    for(int i=1;i<=v;i++)
    {
        int idx=sccArr[i];
        if(len<idx) len=idx;
        resV[idx].push_back(i);
    }
    vector<pair<int,int>> idxV;
    for(int i=1;i<=len;i++)
    {
        idxV.push_back({resV[i][0], i});
    }
    sort(idxV.begin(), idxV.end(), cmp);
    cout<<len<<"\n";
    for(int i=0;i<len;i++)
    {
        int idx=idxV[i].second;
        for(auto& num : resV[idx])
        {
            cout<<num<<" ";
        }
        cout<<-1<<"\n";
    }
}