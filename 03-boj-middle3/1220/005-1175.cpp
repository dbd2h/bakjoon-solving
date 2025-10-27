#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int cross[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[50][50]={0};
    pair<int,int> s1,c1,c2;
    c1={-1,-1};
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='.') arr[i][j]=0;
            else if(s[j]=='#') arr[i][j]=-1;
            else if(s[j]=='S')
            {
                arr[i][j]=0;
                s1={i,j};
            }
            else if(s[j]=='C')
            {
                arr[i][j]=0;
                if(c1.first==-1)
                {
                    c1={i,j};
                }
                else
                {
                    c2={i,j};
                }
            }
        }
    }
    bool check[50][50][4]={0};
    bool check1[50][50][4]={0};
    bool check2[50][50][4]={0};
    queue<pair<pair<int,int>,pair<pair<int,int>,int>>> q;
    q.push({s1,{{1,-1},0}});
    int res=0;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second.first.first;
        int bef=q.front().second.first.second;
        int isC=q.front().second.second;
        q.pop();
        if(isC==1 && x==c2.first && y==c2.second)
        {
            res=c;
            break;
        }
        else if(isC==2 && x==c1.first && y==c1.second)
        {
            res=c;
            break;
        }
        for(int i=0;i<4;i++)
        {
            if(bef==i) continue;
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=n || yp<0 || yp>=m) continue;
            if(arr[xp][yp]==-1) continue;
            if(isC==0)
            {
                if(check[xp][yp][i]) continue;
                if(xp==c1.first && yp==c1.second)
                {
                    q.push({{xp,yp},{{c+1,i},1}});
                }
                else if(xp==c2.first && yp==c2.second)
                {
                    q.push({{xp,yp},{{c+1,i},2}});
                }
                else
                {
                    q.push({{xp,yp},{{c+1,i},0}});
                }
                check[xp][yp][i]=1;
            }
            else if(isC==1)
            {
                if(check1[xp][yp][i]) continue;
                q.push({{xp,yp},{{c+1,i},1}});
                check1[xp][yp][i]=1;
            }
            else if(isC==2)
            {
                if(check2[xp][yp][i]) continue;
                q.push({{xp,yp},{{c+1,i},2}});
                check2[xp][yp][i]=1;
            }
        }
    }
    cout<<res-1;
}