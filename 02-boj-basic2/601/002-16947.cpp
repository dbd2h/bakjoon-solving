#include <iostream>
#include <stack>
#include <queue>
#include <vector>

#define MAX_SIZE 3001

using namespace std;

int main()
{
    vector<int> graph[MAX_SIZE];
    int n;
    cin >> n;
    int parentNode[MAX_SIZE]={0};
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int visit[MAX_SIZE]={0};
    vector<int> cycle[MAX_SIZE];
    stack<int> s;
    int count[MAX_SIZE]={0};
    s.push(1);
    visit[1]=1;
    int isBPSOff=0;
    int isVisit=0;
    int parent=0;
    while(!s.empty())
    {
        int t=s.top();
        for(int i=0;i<graph[t].size();i++)
        {
            int now=graph[t][i];
            s.pop();
            if(s.empty())
            {
                parent=0;
            }
            else
            {
                parent=s.top();
            }
            s.push(t);
            if(!visit[now])
            {
                isVisit=1;
                parentNode[now]=s.top();
                s.push(now);
                visit[now]=1;
                break;
            }
            else if(parentNode[now]!=s.top() && now != parent)
            {
                int cTop=0;
                int cNow;
                cNow=now;
                while(cTop!=now)
                {
                    cTop=s.top();
                    cycle[cTop].push_back(cNow);
                    cycle[cNow].push_back(cTop);
                    cNow=cTop;
                    s.pop();
                }
                isBPSOff=1;
                break;
            }
        }
        if(isBPSOff)
        {
            break;
        }
        if(isVisit)
        {
            isVisit=0;
            continue;
        }
        s.pop();
    }
    for(int i=1;i<=n;i++)
    {
        visit[i]=0;
    }
    int start;
    for(int i=1;i<=n;i++)
    {
        if(!cycle[i].size())
        {
            continue;
        }
        start=i;
        visit[start]=1;
        while(1)
        {
            if(graph[start].size()!=2)
            {
                queue<int> q;
                q.push(start);
                while(!q.empty())
                {
                    int qf=q.front();
                    q.pop();
                    for(int i=0;i<graph[qf].size();i++)
                    {
                        int now=graph[qf][i];
                        if(cycle[start][0]==now || cycle[start][1]==now)
                        {
                            continue;
                        }
                        if(!visit[now])
                        {
                            count[now]=count[qf]+1;
                            visit[now]=1;
                            q.push(now);
                        }
                    }
                }
            }


            if(!visit[cycle[start][0]])
            {
                visit[cycle[start][0]]=1;
                start=cycle[start][0];
                
            }
            else if(!visit[cycle[start][1]])
            {
                visit[cycle[start][1]]=1;
                start=cycle[start][1];
                
            }
            else
            {
                break;
            }
        }
       
        break;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<count[i]<<" ";
    }
}