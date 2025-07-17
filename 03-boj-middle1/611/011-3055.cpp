#include <iostream>
#include <string>
#include <queue>

using namespace std;

char map[50][50]={0};
int count[50][50]={0};

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int r,c;
    cin>>r>>c;
    int fa,fb;
    queue<pair<int,int>> waterQ;
    queue<pair<int,int>> hedgeQ;
    queue<int> countQ;
    queue<int> waterCQ;

    for(int i=0;i<r;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<c;j++)
        {
            map[i][j]=s[j];
            if(s[j]=='S')
            {
                hedgeQ.push({i,j});
                countQ.push(0);
                count[i][j]=1;
                map[i][j]='.';
            }
            if(s[j]=='*')
            {
                waterQ.push({i,j});
                waterCQ.push(0);
            }
            if(s[j]=='D')
            {
                fa=i;
                fb=j;
            }
        }
    }
    int waterPro=0;
    while(!hedgeQ.empty())
    {
        while(!waterCQ.empty() && countQ.front()>waterCQ.front())
        {
            int wa,wb,wc;
            wa=waterQ.front().first;
            wb=waterQ.front().second;
            wc=waterCQ.front();
            waterQ.pop();
            waterCQ.pop();
            for(int i=0;i<4;i++)
            {
                int ap,bp;
                ap=cross[i][0];
                bp=cross[i][1];
                if(ap+wa<0 || ap+wa>=r || bp+wb<0 || bp+wb>=c) continue;
                if(map[ap+wa][bp+wb]!='.') continue;
                waterQ.push({ap+wa,bp+wb});
                waterCQ.push(wc+1);
                map[ap+wa][bp+wb]='*';
            }
        }
        int a,b,co;
        a=hedgeQ.front().first;
        b=hedgeQ.front().second;
        co=countQ.front();
        hedgeQ.pop();
        countQ.pop();
        if(map[a][b]=='*') continue;
        for(int i=0;i<4;i++)
        {
            int ap,bp;
            ap=cross[i][0];
            bp=cross[i][1];
            if(a+ap<0 || a+ap>=r || b+bp<0 || b+bp>=c) continue;
            if(map[a+ap][b+bp]=='D')
            {
                cout<<co+1;
                return 0;
            }
            else if(map[a+ap][b+bp]=='*') continue;
            else if(map[a+ap][b+bp]=='.' && count[a+ap][b+bp]==0)
            {
                hedgeQ.push({a+ap,b+bp});
                countQ.push(co+1);
                count[a+ap][b+bp]=1;
            }
        }
    }
    cout<<"KAKTUS";

}