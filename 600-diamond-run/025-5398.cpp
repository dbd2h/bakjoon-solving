#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define LEN 2001
#define INF 1e9

using namespace std;

int lmatch[501];
int rmatch[501];
int dist[501];

bool bfs(vector<int> graph[501], int n)
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
        for(auto& vWord : graph[cur])
        {
            int hWord=rmatch[vWord];
            if(hWord==0) found=true;
            else if(dist[hWord]==INF)
            {
                q.push(hWord);
                dist[hWord]=dist[cur]+1;
            }
        }
    }
    return found;
}

bool dfs(vector<int> graph[501], int cur)
{
    for(auto& vWord : graph[cur])
    {
        int hWord=rmatch[vWord];
        if(hWord==0 || (dist[hWord]==dist[cur]+1 && dfs(graph,hWord)))
        {
            lmatch[cur]=vWord;
            rmatch[vWord]=cur;
            return true;
        }
    }
    return false;
}

void problem()
{
    int h,v;
    cin>>h>>v;
    int hArr[LEN][LEN];
    int arr[LEN][LEN]={0};
    vector<int> graph[501];
    for(int i=1;i<=h;i++)
    {
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int len=s.size();
        for(int j=0;j<len;j++)
        {
            hArr[y][j+x]=s[j]-'A'+1;
            arr[y][j+x]=i;
        }
    }
    for(int i=1;i<=v;i++)
    {
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int len=s.size();
        for(int j=0;j<len;j++)
        {
            int curI=arr[y+j][x];
            if(curI==0) continue;
            int cur=s[j]-'A'+1;
            if(hArr[y+j][x]==cur) continue;
            graph[curI].push_back(i);
        }
    }
    for(int i=1;i<=h;i++) lmatch[i]=0;
    for(int i=1;i<=v;i++) rmatch[i]=0;
    int res=0;
    while(bfs(graph,h))
    {
        for(int i=1;i<=h;i++)
        {
            if(lmatch[i]==0 && dfs(graph,i)) res++;
        }
    }
    cout<<h+v-res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}