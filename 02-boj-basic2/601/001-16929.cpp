#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int move[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
    int n,m;
    cin>>n>>m;
    char dots[52][52]={0};
    int check[52][52]={0};
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            dots[i][j]=s[j-1];
        }
    }
    int finish=0;
    for(int i=1;i<=n;i++)
    {
        if(finish==1)
        {
            break;
        }
        for(int j=1;j<=m;j++)
        {
            if(finish==1)
            {
                break;
            }
            if(check[i][j]!=0)
            {
                continue;
            }
            check[i][j]=1;
            stack<pair<int,int>> s1;
            s1.push({i,j});
            char now=dots[i][j];
            pair<int,int> a;
            int isAct=0;
            while(!s1.empty())
            {
                int r,c;
                a=s1.top();
                r=a.first;
                c=a.second;
                if(isAct==1)
                {
                    for(int i=0;i<4;i++)
                    {
                        if(check[r][c]==i+1)
                        {
                            continue;
                        }
                        int r1,c1;
                        r1=-move[i][0];
                        c1=-move[i][1];
                        if(dots[r+r1][c+c1]==now&&check[r+r1][c+c1]!=0)
                        {
                            finish=1;
                            break;
                        }
                    }
                }
                if(finish==1)
                {
                    break;
                }
                int isGo=0;
                for(int m=0;m<4;m++)
                {
                    int r1,c1;
                    r1=move[m][0];
                    c1=move[m][1];
                    if(dots[r+r1][c+c1]==now&&check[r+r1][c+c1]==0)
                    {
                        check[r+r1][c+c1]=m+1;
                        s1.push({r+r1,c+c1});
                        isGo=1;
                        isAct=1;
                        break;
                    }
                }
                if(isGo==0)
                {
                    s1.pop();
                    isAct=0;
                }
            }
        }
    }
    if(finish==1)
    {
        cout<<"Yes";
    }
    else
    
    {
        cout<<"No";
    }
}