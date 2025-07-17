#include <iostream>
#include <queue>
#include <string>

using namespace std;

char map[100][100]={0};
int count[100][100][4]={0};
int cross[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; //상,우,하,좌

int main()
{
    int w,h;
    cin>>w>>h;
    int a,b,la,lb;
    a=-1;
    for(int i=0;i<h;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<w;j++)
        {
            map[i][j]=s[j];
            if(a==-1 && s[j]=='C')
            {
                a=i;
                b=j;
            }
            else if(s[j]=='C')
            {
                la=i;
                lb=j;
            }
            for(int k=0;k<4;k++)
            {
                count[i][j][k]=100000;
            }
            
        }
    }

    queue<pair<int,int>> q;
    queue<pair<int,int>> statusQ;
    for(int i=0;i<4;i++)
    {
        int ap,bp;
        ap=cross[i][0];
        bp=cross[i][1];
        count[a+ap][b+bp][i]=0;
        if(a+ap<0 || a+ap>=h || b+bp<0 || b+bp>=w) continue;
        if(a+ap==la && b+bp==lb)
        {
            cout<<0;
            return 0;
        }
        if(map[a+ap][b+bp]!='.') continue;
        q.push({a+ap,b+bp});
        statusQ.push({0,i});
        count[a+ap][b+bp][i]=0;
    }
    while(!q.empty())
    {
        a=q.front().first;
        b=q.front().second;
        int c,dir;
        c=statusQ.front().first;
        dir=statusQ.front().second;
        q.pop();
        statusQ.pop();
        if(count[a][b][dir]<c) continue;
        for(int i=0;i<4;i++)
        {
            if((dir+2)%4==i) continue;
            int ap,bp,nextC;
            ap=cross[i][0];
            bp=cross[i][1];
            nextC=c;
            if(a+ap<0 || a+ap>=h || b+bp<0 || b+bp>=w) continue;
            if(map[a+ap][b+bp]=='*') continue;
            if(dir!=i)
            {
                nextC++;
            }
            if(count[a+ap][b+bp][i]<=nextC) continue;
            count[a+ap][b+bp][i]=nextC;
            q.push({a+ap,b+bp});
            statusQ.push({nextC,i});
        }
    }
    int result=99999;
    for(int i=0;i<4;i++)
    {
        if(result>count[la][lb][i])
        {
            result=count[la][lb][i];
        }
    }
    cout<<result;
}