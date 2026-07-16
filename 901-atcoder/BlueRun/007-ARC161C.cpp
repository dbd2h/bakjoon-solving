#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 200001

using namespace std;
int befColor[LEN];
int color[LEN];
int parent[LEN];
int inci[LEN][2];
vector<int> graph[LEN];

int dfs(int cur, int p)
{
    for(auto &next:graph[cur])
    {
        if(next==p) continue;
        int c=dfs(next,cur);
        if(c==-1) return -1;
        else if(c==0) continue;
        else if(befColor[cur]==0)
        {
            befColor[cur]=c;
            if(p!=0) inci[p][c-1]++;
        } 
        else if(befColor[cur]!=c) return -1;
    }
    if(befColor[cur]==0)
    {
        if(p==0) befColor[cur]=1;
        else
        {
            befColor[cur]=color[p];
            inci[p][color[p]-1]++;
        } 
    }

    if(inci[cur][0]==inci[cur][1]) return color[cur];
    else if((inci[cur][0]>inci[cur][1] && color[cur]==1) || (inci[cur][0]<inci[cur][1] && color[cur]==2)) return 0;
    else return -1;
}

void problem()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        befColor[i]=0;
        parent[i]=0;
        inci[i][0]=inci[i][1]=0;
        graph[i].clear();
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B') color[i+1]=1;
        else color[i+1]=2;
    }
    int res=dfs(1,0);
    if(res==-1)
    {
        cout<<-1<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(befColor[i]==1) cout<<'B';
        else cout<<'W';
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();
    }
}