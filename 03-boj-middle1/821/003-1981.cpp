#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cross[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
vector<int> numV;

bool bfs(int arr[][100],int n,int middle,int minV)
{
    int check[100][100]={0};
    queue<pair<int,int>> q;
    q.push({0,0});
    check[0][0]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xp=cross[i][0];
            int yp=cross[i][1];
            if(x+xp<0 || y+yp<0 || x+xp>=n || y+yp>=n) continue;
            if(check[x+xp][y+yp]) continue;
            int num=arr[x+xp][y+yp];
            if(minV>num || minV+middle<num) continue;
            if(x+xp==n-1 && y+yp==n-1) return true;
            q.push({x+xp,y+yp});
            check[x+xp][y+yp]=1;
        }
    }
    return false;
}

int binarySearch(int arr[][100], int n, int l, int r)
{
    if(l>=r) return r;
    int c=0;
    int middle=(l+r)/2;
    bool m1=false;
    bool f=false;
    for(int i=0;i<numV.size();i++)
    {
        if(i>0 && middle+numV[i-1]>200) break;
        if(numV[i]>arr[0][0] || numV[i]+middle<arr[0][0]) continue;
        m1=bfs(arr,n,middle,numV[i]);
        if(m1) break;
    }
    
    if(!m1) return binarySearch(arr,n,middle+1,r);
    bool m2=false;
    for(int i=0;i<numV.size();i++)
    {
        if(i>0 && middle-1+numV[i-1]>200) break;
        if(numV[i]>arr[0][0] || numV[i]+middle-1<arr[0][0]) continue;
        m2=bfs(arr,n,middle-1,numV[i]);
        if(m2) break;
    }
    if(m2) return binarySearch(arr,n,l,middle-1);
    return middle;
}

int main()
{
    int n;
    cin>>n;
    int arr[100][100]={0};
    int bit[201]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            bit[arr[i][j]]=1;
        }
    }
    for(int i=0;i<201;i++)
    {
        if(bit[i]==1) numV.push_back(i);
    }
    cout<<binarySearch(arr,n,0,200);
}
