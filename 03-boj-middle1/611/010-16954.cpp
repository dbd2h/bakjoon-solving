#include <iostream>
#include <string>
#include <queue>

using namespace std;

int chessboard[8][8]={0};

int cross[9][2]={{0,0},{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

int main()
{
    for(int i=0;i<8;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<8;j++)
        {
            chessboard[i][j] = (s[j]=='#');
        }
    }

    queue<pair<int,int>> q;
    queue<int> countQ;
    q.push({7,0});
    countQ.push(0);

    while(!q.empty())
    {
        int a,b;
        int c;
        a=q.front().first;
        b=q.front().second;
        c=countQ.front();
        q.pop();
        countQ.pop();
        if(c==8)
        {
            cout<<1;
            return 0;
        }

        if(a-c>=0 && chessboard[a-c][b]==1)
        {
            continue;
        }

        for(int i=0;i<9;i++)
        {
            int ap,bp;
            ap=cross[i][0];
            bp=cross[i][1];

            if(a+ap<0 || a+ap>=8 || b+bp<0 || b+bp>=8) continue;

            if(chessboard[a+ap-c][b+bp]==1) continue;

            q.push({a+ap,b+bp});
            countQ.push(c+1);
        }
    }
    cout<<0;
}