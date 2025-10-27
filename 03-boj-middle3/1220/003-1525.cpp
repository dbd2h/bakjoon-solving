#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    string s;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            char c;
            cin>>c;
            s+=c;
        }
    }
    map<string,bool> m;
    m[s]=1;
    queue<pair<string,int>> q;
    q.push({s,0});
    int res=-1;
    while(!q.empty())
    {
        s=q.front().first;
        int c=q.front().second;
        q.pop();
        if(s=="123456780")
        {
            res=c;
            break;
        }
        int puzzle[3][3];
        pair<int,int> zero;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int cur=s[j+i*3]-'0';
                puzzle[i][j]=cur;
                if(puzzle[i][j]==0) zero={i,j};
            }
        }
        for(int i=0;i<4;i++)
        {
            int xp=cross[i][0]+zero.first;
            int yp=cross[i][1]+zero.second;
            if(xp<0 || xp>=3 || yp<0 || yp>=3) continue;
            puzzle[zero.first][zero.second]=puzzle[xp][yp];
            puzzle[xp][yp]=0;
            string next;
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    next+=to_string(puzzle[j][k]);
                }
            }
            puzzle[xp][yp]=puzzle[zero.first][zero.second];
            puzzle[zero.first][zero.second]=0;
            if(m[next]) continue;
            m[next]=1;
            q.push({next,c+1});
        }
    }
    cout<<res;
}