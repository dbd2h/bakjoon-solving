#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cross[6][2]={{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1}};

vector<int> graph[1024];
int countArr[1024];

void graphMaker(bool arr[], bool befArr[], int idx, int num, int gIdx)
{
    if(idx==10)
    {
        graph[gIdx].push_back(num);
        return;
    }
    graphMaker(arr,befArr,idx+1,num*2,gIdx);
    if(idx==0)
    {
        if(arr[idx+1]==1) return;
    }
    else if(idx==9)
    {
        if(befArr[idx-1]==1 || arr[idx-1]==1) return;
    }
    else
    {
        if(befArr[idx-1]==1 || arr[idx-1]==1 || arr[idx+1]==1) return;
    }
    befArr[idx]=1;
    graphMaker(arr,befArr,idx+1,num*2+1,gIdx);
    befArr[idx]=0;
}

void dfs(bool arr[], int idx, int num, int c)
{
    if(idx==10)
    {
        bool befArr[10]={0};
        countArr[num]=c;
        graphMaker(arr,befArr,0,0,num);
        return;
    }
    dfs(arr,idx+1,num*2, c);
    if(idx==0 || arr[idx-1]==0)
    {
        arr[idx]=1;
        dfs(arr,idx+1,num*2+1, c+1);
        arr[idx]=0;
    } 
}

void dpDfs(bool arr[10][10], int dp[10][1024], bool bit[10], int row, int idx, int num, int m, int c)
{
    if(idx==m)
    {
        if(row==0)
        {
            dp[row][num]=c;
            return;
        }
        int maxV=0;
        int maxI=-1;
        for(auto &bef : graph[num])
        {
            if(dp[row-1][bef]>maxV)
            {
                maxV=dp[row-1][bef];
                maxI=bef;
            } 
        }
        dp[row][num]=maxV+c;
        return;
    }
    dpDfs(arr,dp,bit,row,idx+1,num*2,m,c);
    if(arr[row][idx]==1 && (idx==0 || bit[idx-1]==0))
    {
        bit[idx]=1;
        dpDfs(arr,dp,bit,row,idx+1,num*2+1,m,c+1);
        bit[idx]=0;
    }
}

void problem()
{
    int n,m;
    cin>>n>>m;
    bool arr[10][10];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {   
            if(s[j]=='.') arr[i][j]=1;
            else arr[i][j]=0;
        }
    }
    int dp[10][1024]={0};
    for(int i=0;i<n;i++)
    {
        bool bit[10]={0};
        dpDfs(arr,dp,bit,i,0,0,m,0);
    }
    int res=0;
    for(int i=0;i<1024;i++)
    {
        if(dp[n-1][i]>res) res=dp[n-1][i];
    }
    cout<<res<<"\n";
}

int main()
{
    bool arr[10]={0};
    dfs(arr,0,0,0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}