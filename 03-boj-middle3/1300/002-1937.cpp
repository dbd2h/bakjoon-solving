#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int compare(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    return p1.first>p2.first;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> v;
    int arr[500][500];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            v.push_back({arr[i][j],{i,j}});
        }
    }
    sort(v.begin(), v.end(), compare);
    int len=v.size();
    int dp[500][500]={0};
    int res=0;
    for(int i=0;i<len;i++)
    {
        int x=v[i].second.first;
        int y=v[i].second.second;
        int num=v[i].first;
        dp[x][y]=1;
        for(int j=0;j<4;j++)
        {
            int xp=x+cross[j][0];
            int yp=y+cross[j][1];
            if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
            if(arr[xp][yp]<=num) continue;
            int nextV=dp[xp][yp];
            if(dp[x][y]<nextV+1) dp[x][y]=nextV+1;
        }
        if(dp[x][y]>res) res=dp[x][y];
    }
    cout<<res;
}
