#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 100001

using namespace std;

int check[LEN][3][3][2];
vector<pair<int,int>> graph[LEN];

void program()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
        for(int j=0;j<3;j++)
        {
            for(int l=0;l<3;l++) check[i][j][l][0]=check[i][j][l][1]=-1;
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q; // cur, alpha, count, k
    for(int i=0;i<m;i++)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c-'A'});
        check[a][c-'A'][2][0]=check[a][c-'A'][1][0]=check[a][c-'A'][0][0]=0;
        check[a][c-'A'][2][1]=check[a][c-'A'][1][1]=check[a][c-'A'][0][1]=a;
    }
    for(int i=1;i<=n;i++) q.push({{i,-1},{0,k}});
    while(!q.empty())
    {
        int cur=q.front().first.first;
        int alpha=q.front().first.second;
        int c=q.front().second.first;
        int rem=q.front().second.second;
        q.pop();
        if(alpha!=-1 && check[cur][alpha][rem][0]>c) continue;

    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}