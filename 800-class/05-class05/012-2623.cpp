#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    bool graph[1001][1001]={0};
    int befArr[1001]={0};
    for(int i=0;i<m;i++)
    {
        int c;
        cin>>c;
        int bef;
        for(int j=0;j<c;j++)
        {
            int num;
            cin>>num;
            if(j==0) 
            {
                bef=num;
                continue;
            }
            graph[bef][num]=1;
            bef=num;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(graph[i][j]) befArr[j]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(befArr[i]!=0) continue;
        q.push(i);
    }
    int resArr[1000];
    int count=0;
    while(!q.empty())
    {
        int cur=q.front();
        resArr[count]=cur;
        count++;
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(graph[cur][i]==0) continue;
            befArr[i]--;
            if(befArr[i]==0) q.push(i);
        }
    }
    if(count<n) cout<<0;
    else
    {
        for(int i=0;i<n;i++)
        {
            cout<<resArr[i]<<"\n";
        }
    }
}