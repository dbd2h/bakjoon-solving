#include <iostream>

using namespace std;

int board[15][15]={0};

void NQueen(int n, int c, int *num)
{
    if(c==n)
    {
        (*num)+=1;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(board[c][i]==1) continue;
        int qblock[60][2]={0};
        int blockC=0;
        //가로, 세로, 왼오대각선, 오왼대각선
        for(int j=c;j<n;j++)
        {
            if(board[j][i]==0)
            {
                qblock[blockC][0]=j;
                qblock[blockC][1]=i;
                board[j][i]=1;
                blockC++;
            }
            if(i-c+j>=0 && i-c+j<n && board[j][i-c+j]==0)
            {
                qblock[blockC][0]=j;
                qblock[blockC][1]=i-c+j;
                board[j][i-c+j]=1;
                blockC++;
            }
            if(i+c-j>=0 && i+c-j<n && board[j][i+c-j]==0)
            {
                qblock[blockC][0]=j;
                qblock[blockC][1]=i+c-j;
                board[j][i+c-j]=1;
                blockC++;
            }
        }
        NQueen(n,c+1, num);
        for(int j=0;j<blockC;j++)
        {
            board[qblock[j][0]][qblock[j][1]]=0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int num=0;
    NQueen(n,0,&num);
    cout<<num;
}