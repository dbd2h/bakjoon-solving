#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#define MAX_LEN 100'001

using namespace std;

int main()
{
    vector<int> graph[MAX_LEN];
    int order[MAX_LEN]={0};
    int visit[MAX_LEN]={0};
    int parent[MAX_LEN]={0};
    int countG[MAX_LEN]={0};
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        countG[a]++;
        countG[b]++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>order[i];
    }
    visit[1]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(int y : graph[front])
        {
            if(!visit[y])
            {
                visit[y]=1;
                parent[y]=front;
                q.push(y);
            }
        }
    }
    stack<int> s;
    s.push(1);
    int count=2;
    int con=0;
    int isVisit=0;
    int isTrue=1;
    if(order[1]!=1)
    {
        s.pop();
        isTrue=0;
    }
    while(!s.empty())
    {
        int top=s.top();
        if(countG[top]==0)
        {
            s.pop();
            continue;
        }
        if(parent[order[count]]!=top)
        {
            isTrue=0;
            break;
        }
        s.push(order[count]);
        countG[order[count]]--;
        countG[parent[order[count]]]--;
        count++;
    }
    cout<<isTrue;
}