#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;


int lmatch[501];
int rmatch[501];
int dist[501];

bool bfs(vector<int> graph[501], int voteArr[500][3], int v)
{
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(voteArr[i][0]) continue;
        if(lmatch[i]==-1)
        {
            dist[i]=0;
            q.push(i);
        }
        else dist[i]=INF;
    }

    bool found=false;

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto &next : graph[cur])
        {
            int p=rmatch[next];
            if(p==-1) found=true;
            else if(dist[p]==INF)
            {
                dist[p]=dist[cur]+1;
                q.push(p);
            }
        }
    }
    return found;
}

bool dfs(vector<int> graph[501], int cur)
{
    for(auto &next : graph[cur])
    {
        int p=rmatch[next];
        if(p==-1 || (dist[p]==dist[cur]+1 && dfs(graph,p)))
        {
            lmatch[cur]=next;
            rmatch[next]=cur;
            return true;
        }
    }
    return false;
}


void problem()
{
    int c,d,v;
    cin>>c>>d>>v;
    int voteArr[500][3];
    for(int i=0;i<v;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        bool isCat=0;
        if(s1[0]=='C') isCat=1;
        int len1=s1.size();
        int len2=s2.size();
        int num1=0;
        int num2=0;
        for(int j=1;j<len1;j++)
        {
            num1*=10;
            num1+=s1[j]-'0';
        }
        for(int j=1;j<len2;j++)
        {
            num2*=10;
            num2+=s2[j]-'0';
        }
        voteArr[i][0]=isCat;
        voteArr[i][1]=num1;
        voteArr[i][2]=num2;
    }
    vector<int> graph[500];
    for(int i=0;i<v;i++)
    {
        if(voteArr[i][0]) continue;
        for(int j=0;j<v;j++)
        {
            if(voteArr[j][0]==0) continue;
            if(voteArr[i][1]==voteArr[j][2] || voteArr[i][2]==voteArr[j][1]) graph[i].push_back(j);
        }
    }
    for(int i=0;i<v;i++)
    {
        lmatch[i]=-1;
        rmatch[i]=-1;
    }
    while(bfs(graph,voteArr,v))
    {
        for(int i=0;i<v;i++)
        {
            if(voteArr[i][0]) continue;
            if(lmatch[i]==-1) dfs(graph,i);
        }
    }
    int res=v;
    for(int i=0;i<v;i++)
    {
        if(voteArr[i][0]) continue;
        if(lmatch[i]!=-1) res--;
    }
    cout<<res<<"\n";

}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}