#include <iostream>
#include <queue>
#define MAX_LEN 22

using namespace std;

char board[MAX_LEN][MAX_LEN]={0};

int main()
{
    char s[MAX_LEN]={0};
    int n,m;
    pair<int,int> p1, p2;
    p1={0,0};
    p2={0,0};
    cin>>n>>m;
    for(int i=0;i<MAX_LEN;i++)
    {
        for(int j=0;j<MAX_LEN;j++)
        {
            board[i][j]='X';
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='o')
            {
                if(p1.first==0)
                {
                    p1={i+1,j+1};
                }
                else
                {
                    p2={i+1,j+1};
                }
                board[i+1][j+1]='.';
                continue;
            }
            board[i+1][j+1]=s[j];
        }
    }

    queue<pair<pair<int,int>,pair<int,int>>> q;
    queue<int> countQ;
    q.push({p1, p2});
    countQ.push(1);
    int result=-1;
    int x[4]={-1, 0, 1, 0};
    int y[4]={0, -1, 0, 1};
    while(!q.empty())
    {
        int p1_f, p1_s, p2_f, p2_s;
        pair<pair<int,int>,pair<int,int>> p = q.front();
        int count=countQ.front();
        if(count>10)
        {
            result=-1;
            break;
        }
        q.pop();
        countQ.pop();
        p1_f=p.first.first;
        p1_s=p.first.second;
        p2_f=p.second.first;
        p2_s=p.second.second;
        pair<int, int> p1, p2;
        int p1Drop=0;
        for(int i=0;i<4;i++)
        {
            int p1_1, p1_2, p2_1, p2_2;
            p1_1=p1_f+x[i];
            p1_2=p1_s+y[i];
            p2_1=p2_f+x[i];
            p2_2=p2_s+y[i];
            if(board[p1_1][p1_2]=='#')
            {
                p1={p1_1-x[i], p1_2-y[i]};
            }
            if(board[p2_1][p2_2]=='#')
            {
                p2={p2_1-x[i], p2_2-y[i]};
            }
            if(board[p1_1][p1_2]=='.')
            {
                p1={p1_1, p1_2};
            }
            if(board[p2_1][p2_2]=='.')
            {
                p2={p2_1, p2_2};
            }
            if(board[p1_1][p1_2]=='X' && board[p2_1][p2_2]=='X')
            {
                continue;
            }
            else if(board[p1_1][p1_2]=='X' && board[p2_1][p2_2]!='X')
            {
                result=count;
                break;
            }
            else if(board[p1_1][p1_2]!='X' && board[p2_1][p2_2]=='X')
            {
                result=count;
                break;
            }
            q.push({p1,p2});
            countQ.push(count+1);
        }
        if(result!=-1)
        {
            break;
        }
    }
    cout<<result;
    
}