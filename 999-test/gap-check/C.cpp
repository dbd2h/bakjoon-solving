#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

using namespace std;

int main()
{
    bool arr[10][10];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q; // x,y count,dir(down:1, right:0)
    q.push({{0,0},{k,-1}});
    int res=0;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second.first;
        int dir=q.front().second.second;
        q.pop();
        if(x==n-1 && y==n-1)
        {
            res++;
            continue;
        }
        if(dir==-1)
        {
            if(arr[x][y+1]==0) q.push({{x,y+1},{k,0}});
            if(arr[x+1][y]==0) q.push({{x+1,y},{k,1}});
            continue;
        }
        // straight
        if(dir==0)
        {
            if(y+1<n && arr[x][y+1]==0)
            {
                q.push({{x,y+1},{c,dir}});
            }
            if(x+1<n && c>0 && arr[x+1][y]==0)
            {
                q.push({{x+1,y},{c-1,!dir}});
            }
        }
        else
        {
            if(x+1<n && arr[x+1][y]==0)
            {
                q.push({{x+1,y},{c,dir}});
            }
            if(y+1<n && c>0 && arr[x][y+1]==0)
            {
                q.push({{x,y+1},{c-1,!dir}});
            }
        }
    }
    cout<<res;
}