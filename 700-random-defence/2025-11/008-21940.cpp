#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int graph[201][201];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            graph[i][j]=1e8;
            if(i==j) graph[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=c;
    }
    int K;
    cin>>K;
    int city[200];
    for(int i=0;i<K;i++)
    {
        int num;
        cin>>num;
        city[i]=num;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(graph[j][i]+graph[i][k]<graph[j][k]) graph[j][k]=graph[j][i]+graph[i][k];
            }
        }
    }
    int res=1e9;
    vector<int> resV;
    for(int i=1;i<=n;i++)
    {
        int maxV=0;
        bool isF=false;
        for(int j=0;j<K;j++)
        {
            int cur=city[j];
            if(graph[cur][i]>=1e8 || graph[i][cur]>=1e8)
            {
                isF=true;
                break;
            }
            int value=graph[cur][i]+graph[i][cur];
            if(maxV<value) maxV=value;
        }
        if(isF) continue;
        if(res>maxV)
        {
            resV.clear();
            res=maxV;
            resV.push_back(i);
        } 
        else if(res==maxV)
        {
            resV.push_back(i);
        }
    }
    sort(resV.begin(),resV.end());
    int vLen=resV.size();
    for(int i=0;i<vLen;i++)
    {
        cout<<resV[i]<<" ";
    }
}