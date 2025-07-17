#include <iostream>
#include <queue>

using namespace std;

int number[5][5]={0};
int bit[1000000]={0};

int cross[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>number[i][j];
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            queue<pair<int,int>> q;
            queue<pair<int,int>> countQ;
            q.push({i,j});
            countQ.push({1,0});
            while(!q.empty())
            {
                int x,y,c,num;
                x=q.front().first;
                y=q.front().second;
                c=countQ.front().first;
                num=countQ.front().second;
                q.pop();
                countQ.pop();
                if(c==1000000)
                {
                    bit[num]=1;
                    continue;
                }
                for(int k=0;k<4;k++)
                {
                    int xp,yp;
                    xp=cross[k][0];
                    yp=cross[k][1];
                    if(x+xp<0 || x+xp>=5 || y+yp<0 || y+yp>=5) continue;
                    q.push({x+xp,y+yp});
                    countQ.push({c*10,num+c*number[x+xp][y+yp]});
                }
            }

        }
    }
    int res=0;
    for(int i=0;i<1000000;i++)
    {
        res+=bit[i];
    }
    cout<<res;
}
