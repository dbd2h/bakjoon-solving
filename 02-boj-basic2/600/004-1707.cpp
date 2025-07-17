#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> (*graph)[20001], int (*check)[2], int v, int isOdd, int now, int *finish);

int isContain(vector<int> v, int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int v,e;
        cin>>v>>e;
        vector<int> graph[20001];
        int check[v+1][2]={0};
        int a,b;
        int finish=0;
        for(int j=0;j<e;j++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int j=1;j<=v;j++)
        {
            if(check[j][0]==1)
            {
                continue;
            }
            if(finish==1)
            {
                break;
            }
            dfs(&graph, check, v, 1, j, &finish);
        }
        if(finish==1)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }
}

void dfs(vector<int> (*graph)[20001], int (*check)[2], int v, int isOdd, int now, int *finish)
{
    if(isOdd==1)
    {
        check[now][1]=1;
    }
    else
    {
        check[now][1]=2;
    }
    
    check[now][0]=1;
    for(int i=0;i<(*graph)[now].size();i++)
    {
        int value=(*graph)[now][i];
        if(isOdd==1&&check[value][1]==1)
        {
            *finish=1;
            return;
        }
        if(isOdd==0&&check[value][1]==2)
        {
            *finish=1;
            return;
        }
        if(check[value][0]==0)
        {
            dfs(graph, check, v, (isOdd+1)%2, value, finish);
        }
    }
}
