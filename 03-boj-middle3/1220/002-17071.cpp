#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    if(n==k)
    {
        cout<<0;
        return 0;
    }
    int check[500001][2];
    for(int i=0;i<=500000;i++)
    {
        check[i][0]=-1;
        check[i][1]=-1;
    }
    check[n][0]=0;
    queue<pair<int,int>> q;
    q.push({n,0});
    while(!q.empty())
    {
        int cur=q.front().first;
        int c=q.front().second;
        int odd=(c+1)%2;
        q.pop();
        if(cur-1>=0 && check[cur-1][odd]==-1)
        {
            check[cur-1][odd]=c+1;
            q.push({cur-1,c+1});
        }
        if(cur+1<=500000 && check[cur+1][odd]==-1)
        {
            check[cur+1][odd]=c+1;
            q.push({cur+1,c+1});
        }
        if(cur*2<=500000 && check[cur*2][odd]==-1)
        {
            check[cur*2][odd]=c+1;
            q.push({cur*2,c+1});
        }
    }
    int i=0;
    while(true)
    {
        if(k>500000)
        {
            cout<<-1;
            break;
        }
        if(check[k][i%2]!=-1 && check[k][i%2]<=i)
        {
            cout<<i;
            break;
        }
        i++;
        k+=i;
    }
}