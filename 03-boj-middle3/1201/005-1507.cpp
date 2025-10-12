#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int graph[21][21]={0};
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>graph[i][j];
            if(i<j) pq.push({graph[i][j],{i,j}});
        }
    }
    int res=0;
    int resG[21][21]={0};
    while(!pq.empty())
    {
        int w=pq.top().first;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();
        
        if(resG[a][b]==w) continue;
        if(resG[a][b]!=0 && resG[a][b]<w)
        {
            res=-1;
            break;
        }
        resG[a][b]=w;
        resG[b][a]=w;
        res+=w;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(i==j || j==k || k==i) continue;
                    if(resG[j][i]==0 || resG[i][k]==0) continue;
                    if(resG[j][k]==0) resG[j][k]=resG[j][i]+resG[i][k];
                    else resG[j][k]=min(resG[j][k], resG[j][i]+resG[i][k]);
                }
            }
        }
    }
    cout<<res;
}