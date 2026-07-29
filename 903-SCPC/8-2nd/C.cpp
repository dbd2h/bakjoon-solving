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
#define LEN 100001

using namespace std;

vector<int> graph[LEN*3];
vector<int> G[LEN];
vector<int> rG[LEN];
stack<int> st;
bool check[LEN];
int sccId[LEN];
int sccCount;

void dfs1(int cur)
{
    check[cur]=1;
    for(auto&next : G[cur])
    {
        if(check[next]) continue;
        dfs1(next);
    }
    st.push(cur);
}

void dfs2(int cur)
{
    sccId[cur]=sccCount;
    for(auto&next : rG[cur])
    {
        if(sccId[next]!=0) continue;
        dfs2(next);
    }
}

void program()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n*3;i++) graph[i].clear();
    for(int i=1;i<=n;i++)
    {
        G[i].clear();
        rG[i].clear();
        sccId[i]=0;
        sccCount=0;
        check[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;
        if(c=='B') graph[a*3-2].push_back(b*3-1);
        if(c=='C') graph[a*3-1].push_back(b*3);
        if(c=='A') graph[a*3].push_back(b*3-2);
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i]) continue;
        dfs1(i);
    }
    while(!st.empty())
    {
        int cur=st.top();
        st.pop();
        if(sccId[cur]!=0) continue;
        sccCount++;
        dfs2(cur);
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}