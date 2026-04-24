#include <iostream>
#include <vector>

using namespace std;

int dp[14][1<<14]={0};
vector<int> graph[1<<14];
bool befArr[14]={0};
bool curArr[14]={0};

void makeGraph(int m, int idx, int sumV, int befV)
{
    if(idx==m)
    {
        graph[befV].push_back(sumV);
        return;
    }
    if(curArr[idx]) makeGraph(m,idx+1,sumV*2+1,befV);
    else
    {
        makeGraph(m,idx+1,sumV*2,befV);
        if(idx+1!=m && curArr[idx+1]==0)
        {
            curArr[idx]=1;
            curArr[idx+1]=1;
            makeGraph(m,idx+1,sumV*2+1,befV);
            curArr[idx]=0;
            curArr[idx+1]=0;
        }
    }
}

void dfs(int m, int idx, int sumV) // empty->0, filled->1
{
    if(idx==m)
    {
        makeGraph(m,0,0,sumV);
        return;
    }
    curArr[idx]=1;
    dfs(m,idx+1,sumV*2);
    curArr[idx]=0;
    befArr[idx]=1;
    dfs(m,idx+1,sumV*2+1);
    befArr[idx]=0;
}

void dpDfs(bool check[14], int m, int idx, int sumV)
{
    if(idx==m)
    {
        dp[0][sumV]=1;
        return;
    }
    if(check[idx])
    {
        dpDfs(check,m,idx+1,sumV*2+1);
        return;
    }
    dpDfs(check,m,idx+1,sumV*2);
    if(idx!=m-1)
    {
        check[idx]=1;
        check[idx+1]=1;
        dpDfs(check,m,idx+1,sumV*2+1);
        check[idx]=0;
        check[idx+1]=0;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    dfs(m,0,0);
    bool check[14]={0};
    dpDfs(check,m,0,0);
    int div=9901;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            for(auto& next : graph[j])
            {
                dp[i][next]+=dp[i-1][j];
                dp[i][next]%=div;
            }
        }
    }
    cout<<dp[n-1][(1<<m)-1];
}