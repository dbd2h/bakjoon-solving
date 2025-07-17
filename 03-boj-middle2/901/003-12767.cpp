#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tree[1048576]={0};
vector<int> v[50];

void binaryTree(int s, int k, int num, int n)
{
    if(tree[n]==0)
    {
        tree[n]=num;
        v[s].push_back(n);
        return;
    }
    if(tree[n]>num) binaryTree(s,k,num,n*2);
    else if(tree[n]<num) binaryTree(s,k,num,n*2+1);
    return;
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int num;
        for(int j=0;j<k;j++)
        {
            cin>>num;
            binaryTree(i,k,num,1);
        }
        for(int j=0;j<k;j++)
        {
            int index=v[i][j];
            tree[index]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    int graph[50][50]={0};
    for(int i=1;i<k;i++)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=x+1;y<n;y++)
            {
                if(v[x][i]!=v[y][i]) graph[x][y]=1;
            }
        }
    }
    int bit[50]={0};
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(bit[i]!=0) continue;
        c++;
        bit[i]=c;
        for(int j=i+1;j<n;j++)
        {
            if(graph[i][j]==0) bit[j]=c;
        }
    }
    cout<<c;
}