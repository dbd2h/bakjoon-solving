#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[200001];

void dfs(int s, int p, int *result, int bit[])
{
    if(bit[s]==1)
    {
        (*result)++;
        return;
    } 
    for(int i=0;i<v[s].size();i++)
    {
        if(v[s][i]==p) continue;
        if(p==0 && bit[v[s][i]]==1) continue;
        dfs(v[s][i],s,result,bit);
    }
}

void program()
{
    int n;
    cin>>n;
    
    int bit[200001]={0};
    
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        bit[a]++;
        bit[b]++;
    }
    if(n==2)
    {
        cout<<0<<"\n";
        return;
    }
    int startV=-1;
    int maxV=0;
    for(int i=1;i<=n;i++)
    {
        if(bit[i]<=1) continue;
        int c=0;
        for(int j=0;j<v[i].size();j++)
        {
            int next=v[i][j];
            if(bit[next]==1) c++;
        }
        if(c>maxV)
        {
            maxV=c;
            startV=i;
        }
    }
    int result=0;
    dfs(startV,0,&result,bit);
    cout<<result<<"\n";
    for(int i=1;i<=n;i++)
    {
        v[i].clear();
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}