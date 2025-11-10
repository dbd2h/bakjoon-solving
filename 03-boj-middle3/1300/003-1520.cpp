#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int compare(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    return p1.first<p2.first;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[500][500];
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            v.push_back({arr[i][j],{i,j}});
        }
    }
    sort(v.begin(),v.end(),compare);
    int dp[500][500]={0};
    dp[n-1][m-1]=1;
    int len=v.size();
    for(int i=0;i<len;i++)
    {
        int x=v[i].second.first;
        int y=v[i].second.second;
        int num=v[i].first;
        if(x==n-1 && y==m-1) continue;
        for(int j=0;j<4;j++)
        {
            int xp=x+cross[j][0];
            int yp=y+cross[j][1];
            if(xp<0 || xp>=n || yp<0 || yp>=m) continue;
            if(arr[xp][yp]>=arr[x][y]) continue;
            dp[x][y]+=dp[xp][yp];
        }
    }
    cout<<dp[0][0];
}