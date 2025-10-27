#include <iostream>
#include <queue>
#include <string>

#define LEN 1500

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int r,c;
    cin>>r>>c;
    pair<int,int> swan1,swan2;
    swan1={-1,-1};
    int lake[LEN][LEN];
    queue<pair<pair<int,int>,int>> q;
    int left=0;
    int right=0;
    for(int i=0;i<r;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<c;j++)
        {
            if(s[j]=='X')
            {
                lake[i][j]=-1;
                continue;
            } 
            lake[i][j]=0;
            q.push({{i,j},0});
            if(s[j]=='L')
            {
                if(swan1.first==-1)
                {
                    swan1={i,j};
                }
                else
                {
                    swan2={i,j};
                }
            }
        }
    }
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int count=q.front().second;
        if(count>right) right=count;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
            if(lake[xp][yp]!=-1) continue;
            lake[xp][yp]=count+1;
            q.push({{xp,yp},count+1});
        }
    }
    
    int res=-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        int middle2=middle-1;
        bool isF=false;
        queue<pair<int,int>> resQ;
        resQ.push(swan1);
        bool check[LEN][LEN]={0};
        check[swan1.first][swan1.second]=1;
        while(!resQ.empty())
        {
            int x=resQ.front().first;
            int y=resQ.front().second;
            resQ.pop();
            if(x==swan2.first && y==swan2.second)
            {
                isF=true;
                break;
            }
            for(int j=0;j<4;j++)
            {
                int xp=x+cross[j][0];
                int yp=y+cross[j][1];
                if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
                if(check[xp][yp]) continue;
                check[xp][yp]=1;
                if(lake[xp][yp]>middle) continue;
                resQ.push({xp,yp});
            }
        }
        if(!isF)
        {
            left=middle+1;
            continue;
        }
        if(middle==0)
        {
            res=0;
            break;
        }
        bool isF2=false;
        queue<pair<int,int>> resQ2;
        resQ2.push(swan1);
        bool check2[LEN][LEN]={0};
        check2[swan1.first][swan1.second]=1;
        while(!resQ2.empty())
        {
            int x=resQ2.front().first;
            int y=resQ2.front().second;
            resQ2.pop();
            if(x==swan2.first && y==swan2.second)
            {
                isF2=true;
                break;
            }
            for(int j=0;j<4;j++)
            {
                int xp=x+cross[j][0];
                int yp=y+cross[j][1];
                if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
                if(check2[xp][yp]) continue;
                check2[xp][yp]=1;
                if(lake[xp][yp]>middle2) continue;
                resQ2.push({xp,yp});
            }
        }
        if(!isF2)
        {
            res=middle;
            break;
        }
        else
        {
            right=middle-1;
            continue;
        }
    }
    cout<<res;
}