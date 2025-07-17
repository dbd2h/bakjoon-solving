#include <iostream>

using namespace std;
char board[100][100];
int check[100][100]={0};

int cross[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int res[10000][3]={0};

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='*') check[i][j]=1;
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='.') continue;
            int isCross=1;
            for(int k=0;k<4;k++)
            {
                int pa=cross[k][0];
                int pb=cross[k][1];
                if(i+pa<0 || i+pa>=n || j+pb<0 || j+pb>=m || board[i+pa][j+pb]=='.')
                {
                    isCross=0;
                    break;
                }
            }
            if(isCross==0)
            {
                continue;
            }
            check[i][j]=0;
            res[result][0]=i+1;
            res[result][1]=j+1;
            res[result][2]=1;
            result++;
            for(int k=0;k<4;k++)
            {
                check[i+cross[k][0]][j+cross[k][1]]=0;
            }
            int len=2;
            while(true)
            {
                int isCross=1;
                for(int k=0;k<4;k++)
                {
                    int pa=cross[k][0]*len;
                    int pb=cross[k][1]*len;
                    if(i+pa<0 || i+pa>=n || j+pb<0 || j+pb>=m || board[i+pa][j+pb]=='.')
                    {
                        isCross=0;
                        break;
                    }
                }
                if(isCross==0) break;
                res[result-1][2]=len;
                for(int k=0;k<4;k++)
                {
                    check[i+cross[k][0]*len][j+cross[k][1]*len]=0;
                }
                len++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(check[i][j]==1)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<result<<"\n";
    for(int i=0;i<result;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}