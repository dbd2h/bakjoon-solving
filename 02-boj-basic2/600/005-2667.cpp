#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int bfs(int (*map)[27], int (*check)[27], int r, int c);

int main()
{
    int map[27][27]={0};
    int n;
    cin>>n;
    int check[27][27]={0};
    vector<int> v;
    int count=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]=='1')
            {
                map[i+1][j+1]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(map[i][j]==1&&check[i][j]==0)
            {
                count++;
                int tot;
                check[i][j]=1;
                tot=bfs(map, check, i, j);
                v.push_back(tot);
            }
        }
    }
    sort(v.begin(), v.end());
    cout<<count<<"\n";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\n";
    }
}

int bfs(int (*map)[27], int (*check)[27], int r, int c)
{
    int tot=0;
    queue <pair<int, int>> q;
    q.push({r,c});
    while(!q.empty())
    {
        pair <int, int> a;
        a=q.front();
        q.pop();
        tot++;
        int r1,c1;
        r1=a.first;
        c1=a.second;
        for(int i=-1;i<=1;i+=2)
        {
            if(map[r1+i][c1]==1&&check[r1+i][c1]==0)
            {
                q.push({r1+i, c1});
                check[r1+i][c1]=1;
            }
            if(map[r1][c1+i]==1&&check[r1][c1+i]==0)
            {
                q.push({r1, c1+i});
                check[r1][c1+i]=1;
            }
        }
    }
    return tot;
}