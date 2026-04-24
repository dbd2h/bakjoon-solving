#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[51];
int matchR[51]={0};


bool dfs(int cur, bool check[])
{
    for(auto& next : graph[cur])
    {
        if(check[next]) continue;
        int w=matchR[next];
        check[next]=1;
        if(w==cur) continue;
        if(w==0 || dfs(w,check))
        {
            matchR[next]=cur;
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int shark[51][3];
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        shark[i][0]=a;
        shark[i][1]=b;
        shark[i][2]=c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            bool isSelected=false;
            if(shark[i][0]>=shark[j][0] && shark[i][1]>=shark[j][1] && shark[i][2]>=shark[j][2])
            {
                graph[i].push_back(j);
                isSelected=true;
            } 
            if(!isSelected && shark[i][0]<=shark[j][0] && shark[i][1]<=shark[j][1] && shark[i][2]<=shark[j][2])
            {
                graph[j].push_back(i);
            } 
        }
    }
    for(int i=1;i<=n;i++)
    {
        bool check[51]={0};
        if(dfs(i,check))
        {
            for(int j=0;j<=n;j++) check[j]=0;
            dfs(i,check);
        }
        
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(matchR[i]==0) continue;
        res++;
    }
    cout<<n-res;
}