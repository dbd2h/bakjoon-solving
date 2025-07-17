#include <iostream>

using namespace std;

int pi[5]={0};
int board[20][20]={0};
int maxValue=0;
int finish=0;

void game2048(int n);

void piMaker(int count, int n)
{
    //i==2 : up, i==3 : down, i==0 : left, i==1 : right
    if(count==5)
    {
        game2048(n);
        return;
    }
    
    for(int i=0;i<=3;i++)
    {
        pi[count]=i;
        piMaker(count+1, n);
        if(finish==1)
        {
            return;
        }
    }
}

void game2048(int n)
{
    int copyBoard[20][20]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            copyBoard[i][j]=board[i][j];
        }
    }
    for(int i=0;i<5;i++)
    {
        if(pi[i]==0)
        {
            for(int j=0;j<n;j++)
            {
                int isSumed=0;
                int filled=0;
                if(copyBoard[j][0]!=0)
                {
                    filled++;
                }
                for(int k=1;k<n;k++)
                {
                    if(copyBoard[j][k]==0)
                    {
                        continue;
                    }
                    if(filled>0 && isSumed==0 && copyBoard[j][filled-1]==copyBoard[j][k])
                    {
                        isSumed=1;
                        copyBoard[j][filled-1]*=2;
                        continue;
                    }
                    isSumed=0;
                    copyBoard[j][filled]=copyBoard[j][k];
                    filled++;
                }
                for(int k=filled;k<n;k++)
                {
                    copyBoard[j][k]=0;
                }
            }
        }
        else if(pi[i]==1)
        {
            for(int j=0;j<n;j++)
            {
                int isSumed=0;
                int filled=n-1;
                if(copyBoard[j][n-1]!=0)
                {
                    filled--;
                }
                for(int k=n-2;k>=0;k--)
                {
                    if(copyBoard[j][k]==0)
                    {
                        continue;
                    }
                    if(filled<n-1 && isSumed==0 && copyBoard[j][filled+1]==copyBoard[j][k])
                    {
                        isSumed=1;
                        copyBoard[j][filled+1]*=2;
                        continue;
                    }
                    isSumed=0;
                    copyBoard[j][filled]=copyBoard[j][k];
                    filled--;
                }
                for(int k=filled;k>=0;k--)
                {
                    copyBoard[j][k]=0;
                }
            }
        }
        else if(pi[i]==2)
        {
            for(int j=0;j<n;j++)
            {
                int isSumed=0;
                int filled=0;
                if(copyBoard[0][j]!=0)
                {
                    filled++;
                }
                for(int k=1;k<n;k++)
                {
                    if(copyBoard[k][j]==0)
                    {
                        continue;
                    }
                    if(filled>0 && isSumed==0 && copyBoard[filled-1][j]==copyBoard[k][j])
                    {
                        isSumed=1;
                        copyBoard[filled-1][j]*=2;
                        continue;
                    }
                    isSumed=0;
                    copyBoard[filled][j]=copyBoard[k][j];
                    filled++;
                }
                for(int k=filled;k<n;k++)
                {
                    copyBoard[k][j]=0;
                }
            }
        }
        else if(pi[i]==3)
        {
            for(int j=0;j<n;j++)
            {
                int isSumed=0;
                int filled=n-1;
                if(copyBoard[n-1][j]!=0)
                {
                    filled--;
                }
                for(int k=n-2;k>=0;k--)
                {
                    if(copyBoard[k][j]==0)
                    {
                        continue;
                    }
                    if(filled<n-1 && isSumed==0 && copyBoard[filled+1][j]==copyBoard[k][j])
                    {
                        isSumed=1;
                        copyBoard[filled+1][j]*=2;
                        continue;
                    }
                    isSumed=0;
                    copyBoard[filled][j]=copyBoard[k][j];
                    filled--;
                }
                for(int k=filled;k>=0;k--)
                {
                    copyBoard[k][j]=0;
                }
            }
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(max<copyBoard[i][j])
            {
                max=copyBoard[i][j];
            }
        }
    }
    if(max>maxValue)
    {
        maxValue=max;
    }
}

int main()
{
    int n;
    cin>>n;
    int sum;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
            sum+=board[i][j];
        }
    }
    piMaker(0,n);
    cout<<maxValue;
}