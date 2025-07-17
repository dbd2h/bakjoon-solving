#include <iostream>
#include <queue>
#include <string>

using namespace std;

int cross[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int main()
{
    int n;
    cin>>n;
    char arr[100][100]={0};
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            arr[i][j]=s[j];
        }
    }

    int normalCount[100][100]={0};
    int normalNum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(normalCount[i][j]==1) continue;
            char nowColor=arr[i][j];
            queue<pair<int,int>> q;
            q.push({i,j});
            normalCount[i][j]=1;
            while(!q.empty())
            {
                int a,b;
                a=q.front().first;
                b=q.front().second;
                q.pop();
                for(int c=0;c<4;c++)
                {
                    int ap,bp;
                    ap=cross[c][0];
                    bp=cross[c][1];
                    if(a+ap<0 || a+ap>=n || b+bp<0 || b+bp>=n) continue;
                    if(normalCount[a+ap][b+bp]==1) continue;
                    if(arr[a+ap][b+bp]!=nowColor) continue;
                    normalCount[a+ap][b+bp]=1;
                    q.push({a+ap,b+bp});
                }
            }
            normalNum++;
        }
    }
    int colBliCount[100][100]={0};
    int colBliNum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(colBliCount[i][j]==1) continue;
            char nowColor=arr[i][j];
            queue<pair<int,int>> q;
            q.push({i,j});
            colBliCount[i][j]=1;
            while(!q.empty())
            {
                int a,b;
                a=q.front().first;
                b=q.front().second;
                q.pop();
                for(int c=0;c<4;c++)
                {
                    int ap,bp;
                    ap=cross[c][0];
                    bp=cross[c][1];
                    if(a+ap<0 || a+ap>=n || b+bp<0 || b+bp>=n) continue;
                    if(colBliCount[a+ap][b+bp]==1) continue;
                    if(arr[a+ap][b+bp]!=nowColor && !(nowColor=='R' && arr[a+ap][b+bp]=='G') && !(nowColor=='G' && arr[a+ap][b+bp]=='R')) continue;
                    colBliCount[a+ap][b+bp]=1;
                    q.push({a+ap,b+bp});
                }
            }
            colBliNum++;
        }
    }

    cout<<normalNum<<" "<<colBliNum;
}