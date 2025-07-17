#include <iostream>

using namespace std;

int paper[27*27*3][27*27*3]={0};
int countNum[3]={0};

void paperCut(int n, int row, int col)
{
    int num=paper[row][col];
    for(int i=row;i<row+n;i++)
    {
        for(int j=col;j<col+n;j++)
        {
            if(paper[i][j]!=num)
            {
                for(int a=0;a<n;a+=n/3)
                {
                    for(int b=0;b<n;b+=n/3)
                    {
                        paperCut(n/3, row+a,col+b);
                    }
                }
                return;
            }
        }
    }
    countNum[num+1]++;
    return;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>paper[i][j];
        }
    }
    paperCut(n,0,0);
    for(int i=0;i<3;i++)
    {
        cout<<countNum[i]<<"\n";
    }
}





