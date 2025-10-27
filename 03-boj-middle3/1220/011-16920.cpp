#include <iostream>
#include <queue>
#include <string>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    int sArr[10];
    queue<pair<pair<int,int>,int>> q[10];
    for(int i=1;i<=p;i++)
    {
        cin>>sArr[i];
    }
    int map[1000][1000];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            char cur=s[j];
            if(cur=='.') map[i][j]=0;
            else if(cur=='#') map[i][j]=-1;
            else
            {
                q[cur-'0'].push({{i,j},0});
                map[i][j]=cur-'0';
            }
        }
    }
    int idx=1;
    bool isF[10]={0};
    int fCount=0;
    while(true)
    {
        for(int i=1;i<=p;i++)
        {
            if(isF[i]) continue;
            int st=sArr[i]*idx;
            queue<pair<pair<int,int>,int>> &cq=q[i];
            while(!cq.empty())
            {
                int x=cq.front().first.first;
                int y=cq.front().first.second;
                int count=cq.front().second;
                if(count>=st) break;
                cq.pop();
                for(int j=0;j<4;j++)
                {
                    int xp=x+cross[j][0];
                    int yp=y+cross[j][1];
                    if(xp<0 || xp>=n || yp<0 || yp>=m) continue;
                    if(map[xp][yp]!=0) continue;
                    map[xp][yp]=i;
                    cq.push({{xp,yp},count+1});
                }
            }
            if(cq.empty())
            {
                isF[i]=1;
                fCount++;
            }
        }
        if(fCount==p) break;
        idx++;
    }
    int res[10]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int cur=map[i][j];
            if(cur<=0) continue;
            res[cur]++;
        }
    }
    for(int i=1;i<=p;i++)
    {
        cout<<res[i]<<" ";
    }
}