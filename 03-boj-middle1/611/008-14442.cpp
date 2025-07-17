#include <iostream>
#include <queue>
#include <string>

#define MAX_LEN 1000

using namespace std;

int map[MAX_LEN][MAX_LEN]={0};
int count[MAX_LEN][MAX_LEN][11]={0};

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
    q.push({0,0});
    countQ.push({1, k});
    for(int i=k;i>=0;i--)
    {
        count[0][0][i]=1;
    }
    while(!q.empty())
    {
        int a,b,c,br;
        a=q.front().first;
        b=q.front().second;
        c=countQ.front().first;
        br=countQ.front().second;
        q.pop();
        countQ.pop();
        if(c!=count[a][b][br])
        {
            continue;
        }
        if(a-1>=0)
        {
            if(map[a-1][b]==1 && br>0)
            {
                if(count[a-1][b][br-1]==0 || count[a-1][b][br-1]>c+1)
                {
                    q.push({a-1,b});
                    countQ.push({c+1, br-1});
                    for(int i=br-1;i>=0;i--)
                    {
                        if(count[a-1][b][i]!=0 && count[a-1][b][i]<c+1)
                        {
                            break;
                        }
                        count[a-1][b][i]=c+1;
                    }
                }
            }
            else if(map[a-1][b]==0)
            {
                if(count[a-1][b][br]==0 || count[a-1][b][br]>c+1)
                {
                    q.push({a-1,b});
                    countQ.push({c+1, br});
                    for(int i=br;i>=0;i--)
                    {
                        if(count[a-1][b][i]!=0 && count[a-1][b][i]<c+1)
                        {
                            break;
                        }
                        count[a-1][b][i]=c+1;
                    }
                }
            }
        }
        if(a+1<n)
        {
            if(map[a+1][b]==1 && br>0)
            {
                if(count[a+1][b][br-1]==0 || count[a+1][b][br-1]>c+1)
                {
                    q.push({a+1,b});
                    countQ.push({c+1, br-1});
                    for(int i=br-1;i>=0;i--)
                    {
                        if(count[a+1][b][i]!=0 && count[a+1][b][i]<c+1)
                        {
                            break;
                        }
                        count[a+1][b][i]=c+1;
                    }
                }
            }
            else if(map[a+1][b]==0)
            {
                if(count[a+1][b][br]==0 || count[a+1][b][br]>c+1)
                {
                    q.push({a+1,b});
                    countQ.push({c+1, br});
                    for(int i=br;i>=0;i--)
                    {
                        if(count[a+1][b][i]!=0 && count[a+1][b][i]<c+1)
                        {
                            break;
                        }
                        count[a+1][b][i]=c+1;
                    }
                }
            }
        }
        if(b-1>=0)
        {
            if(map[a][b-1]==1 && br>0)
            {
                if(count[a][b-1][br-1]==0 || count[a][b-1][br-1]>c+1)
                {
                    q.push({a,b-1});
                    countQ.push({c+1, br-1});
                    for(int i=br-1;i>=0;i--)
                    {
                        if(count[a][b-1][i]!=0 && count[a][b-1][i]<c+1)
                        {
                            break;
                        }
                        count[a][b-1][i]=c+1;
                    }
                }
            }
            else if(map[a][b-1]==0)
            {
                if(count[a][b-1][br]==0 || count[a][b-1][br]>c+1)
                {
                    q.push({a,b-1});
                    countQ.push({c+1, br});
                    for(int i=br;i>=0;i--)
                    {
                        if(count[a][b-1][i]!=0 && count[a][b-1][i]<c+1)
                        {
                            break;
                        }
                        count[a][b-1][i]=c+1;
                    }
                }
            }
        }
        if(b+1<m)
        {
            if(map[a][b+1]==1 && br>0)
            {
                if(count[a][b+1][br-1]==0 || count[a][b+1][br-1]>c+1)
                {
                    q.push({a,b+1});
                    countQ.push({c+1, br-1});
                    for(int i=br-1;i>=0;i--)
                    {
                        if(count[a][b+1][i]!=0 && count[a][b+1][i]<c+1)
                        {
                            break;
                        }
                        count[a][b+1][i]=c+1;
                    }
                }
            }
            else if(map[a][b+1]==0)
            {
                if(count[a][b+1][br]==0 || count[a][b+1][br]>c+1)
                {
                    q.push({a,b+1});
                    countQ.push({c+1, br});
                    for(int i=br;i>=0;i--)
                    {
                        if(count[a][b+1][i]!=0 && count[a][b+1][i]<c+1)
                        {
                            break;
                        }
                        count[a][b+1][i]=c+1;
                    }
                }
            }
        }
    }
    if(count[n-1][m-1][0]!=0)
    {
        cout<<count[n-1][m-1][0];
    }
    else
    {
        cout<<-1;
    }
    
}