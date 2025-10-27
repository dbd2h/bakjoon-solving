#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int map[100000][2];
    for(int i=0;i<2;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            map[j][i]=s[j]-'0';
        }
    }
    bool check[100000][2]={0};
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    int res=0;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second;
        q.pop();
        if(x-1>c && map[x-1][y]==1 && check[x-1][y]==0)
        {
            q.push({{x-1,y},c+1});
            check[x-1][y]=1;
        }
        if(x+k>=n)
        {
            res=1;
            break;
        }
        if(map[x+1][y]==1 && check[x+1][y]==0)
        {
            q.push({{x+1,y},c+1});
            check[x+1][y]=1;
        }
        if(map[x+k][(y+1)%2]==1 && check[x+k][(y+1)%2]==0)
        {
            q.push({{x+k,(y+1)%2},c+1});
            check[x+k][(y+1)%2]=1;
        }
    }
    cout<<res;
}