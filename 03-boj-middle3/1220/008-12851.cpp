#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int check[100001][2];
    for(int i=0;i<=100000;i++)
    {
        check[i][0]=-1;
        check[i][1]=0;
    }
    check[n][0]=0;
    check[n][1]=1;
    queue<pair<int,int>> q;
    q.push({n,0});
    while(!q.empty())
    {
        int cur=q.front().first;
        int c=q.front().second;
        q.pop();
        if(cur==k) break;
        if(cur-1>=0)
        {
            if(check[cur-1][0]==-1)
            {
                check[cur-1][0]=c+1;
                q.push({cur-1,c+1});
            }
            if(check[cur-1][0]==c+1) check[cur-1][1]+=check[cur][1];
        }
        if(cur+1<=100000)
        {
            if(check[cur+1][0]==-1)
            {
                check[cur+1][0]=c+1;
                q.push({cur+1,c+1});
            }
            if(check[cur+1][0]==c+1) check[cur+1][1]+=check[cur][1];
        }
        if(cur*2<=100000)
        {
            if(check[cur*2][0]==-1)
            {
                check[cur*2][0]=c+1;
                q.push({cur*2,c+1});
            }
            if(check[cur*2][0]==c+1) check[cur*2][1]+=check[cur][1];
        }
    }
    cout<<check[k][0]<<"\n"<<check[k][1];
}