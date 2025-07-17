#include <iostream>
#include <queue>

using namespace std;

int map[20][20]={0};

int cross[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

int main()
{
    int n;
    cin>>n;

    int sa,sb;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==9)
            {
                map[i][j]=0;
                sa=i;
                sb=j;
            }
        }
    }
    
    int count=0;
    int level=2;
    int exp=0;
    while(true)
    {
        int pass[20][20]={0};
        queue<pair<int,int>> q;
        queue<int> countQ;
        q.push({sa,sb});
        countQ.push(0);
        pass[sa][sb]=1;
        int move=0;
        while(!q.empty())
        {
            int a,b,c;
            a=q.front().first;
            b=q.front().second;
            c=countQ.front();
            q.pop();
            countQ.pop();
            if(move!=0 && move==c)
            {
                break;
            }
            for(int i=0;i<4;i++)
            {
                int ap,bp;
                ap=cross[i][0];
                bp=cross[i][1];
                if(a+ap<0 || a+ap>=n || b+bp<0 || b+bp>=n) continue;
                if(pass[a+ap][b+bp]==1 || map[a+ap][b+bp]>level) continue;
                if(map[a+ap][b+bp]<level && map[a+ap][b+bp]!=0)
                {
                    pass[a+ap][b+bp]=1;
                    if(move==0)
                    {
                        sa=a+ap;
                        sb=b+bp;
                        move=c+1;
                        continue;
                    }
                    if(sa>a+ap)
                    {
                        sa=a+ap;
                        sb=b+bp;
                        continue;
                    }
                    else if(sa==a+ap && sb>b+bp)
                    {
                        sa=a+ap;
                        sb=b+bp;
                        continue;
                    }
                }
                if((map[a+ap][b+bp]==level || map[a+ap][b+bp]==0) && pass[a+ap][b+bp]==0)
                {
                    q.push({a+ap,b+bp});
                    countQ.push(c+1);
                    pass[a+ap][b+bp]=1;
                }
            }
        }
        if(move==0)
        {
            break;
        }
        count+=move;
        map[sa][sb]=0;
        exp=(exp+1)%level;
        level = exp==0 ? level+1 : level;
    }
    cout<<count;
}