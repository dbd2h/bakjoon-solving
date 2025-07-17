#include <iostream>
#include <string>
#include <queue>

#define MAX_LEN 1'000

using namespace std;

int map[MAX_LEN][MAX_LEN]={0};
int count[MAX_LEN][MAX_LEN][11][2]={0};

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            map[i][j]=s[j]-'0';
        }
    }

    queue<pair<int,int>> q;
    queue<pair<int,int>> countQ;
    queue<int> day;
    q.push({0,0});
    countQ.push({1,k});
    day.push(1);
    for(int i=k;i>=0;i--)
    {
        count[0][0][i][1]=1;
        count[0][0][i][0]=1;
    }
    while(!q.empty())
    {
        int a,b;
        int c,br;
        int isDay;
        a=q.front().first;
        b=q.front().second;
        c=countQ.front().first;
        br=countQ.front().second;
        isDay=day.front();
        q.pop();
        countQ.pop();
        day.pop();
        if(c>count[a][b][br][isDay]) continue;
        for(int i=0;i<4;i++)
        {
            int ap,bp;
            ap=cross[i][0];
            bp=cross[i][1];
            if(a+ap<0 || a+ap>=n || b+bp<0 || b+bp>=m) continue;

            if(map[a+ap][b+bp]==1 && br>0)
            {
                if(isDay==1)
                {
                    if(count[a+ap][b+bp][br-1][0]>c+1 || count[a+ap][b+bp][br-1][0]==0)
                    {
                        q.push({a+ap,b+bp});
                        countQ.push({c+1, br-1});
                        day.push(0);

                        for(int j=br-1;j>=0;j--)
                        {
                            if(count[a+ap][b+bp][j][0]<=c+1 && count[a+ap][b+bp][j][0]!=0) break;
                            count[a+ap][b+bp][j][0]=c+1;
                        }
                    }
                }
                else
                {
                    if(count[a+ap][b+ap][br-1][1]>c+1 || count[a+ap][b+bp][br-1][1]==0)
                    {
                        q.push({a,b});
                        countQ.push({c+1, br});
                        day.push(1);

                        for(int j=br;j>=0;j--)
                        {
                            if(count[a][b][j][1]<=c+1 && count[a][b][j][1]!=0) break;
                            count[a][b][j][1]=c+1;
                        }
                    }
                }
            }
            else if(map[a+ap][b+bp]==0)
            {
                if(isDay==1)
                {
                    if(count[a+ap][b+bp][br][0]>c+1 || count[a+ap][b+bp][br][0]==0)
                    {
                        q.push({a+ap,b+bp});
                        countQ.push({c+1, br});
                        day.push(0);

                        for(int j=br;j>=0;j--)
                        {
                            if(count[a+ap][b+bp][j][0]<=c+1 && count[a+ap][b+bp][j][0]!=0) break;
                            count[a+ap][b+bp][j][0]=c+1;
                        }
                    }
                }
                else
                {
                    if(count[a+ap][b+bp][br][1]>c+1 || count[a+ap][b+bp][br][1]==0)
                    {
                        q.push({a+ap,b+bp});
                        countQ.push({c+1, br});
                        day.push(1);

                        for(int j=br;j>=0;j--)
                        {
                            if(count[a+ap][b+bp][j][1]<=c+1 && count[a+ap][b+bp][j][1]!=0) break;
                            count[a+ap][b+bp][j][1]=c+1;
                        }
                    }
                }
            }
        }
    }
    int result=count[n-1][m-1][0][0];
    if(result==0 || (result>count[n-1][m-1][0][1] && count[n-1][m-1][0][1]!=0)) result=count[n-1][m-1][0][1];
    if(result==0)
    {
        cout<<-1;
        return 0;
    }
    cout<<result;
}