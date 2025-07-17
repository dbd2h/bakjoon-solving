#include <iostream>

using namespace std;

int sudoku[10][10]={0};
int sudokuCheck[10][10][10]={0};
int sudokuZero[81][2]={0};
int finish=0;

void checkS(int x, int y, int checked[27][2])
{
    int count=0;
    int num=sudoku[x][y];
    for(int i=1;i<=9;i++)
    {
        if(sudoku[i][y]==0 && sudokuCheck[i][y][num]==0)
        {
            sudokuCheck[i][y][num]=1;
            sudokuCheck[i][y][0]++;
            checked[count][0]=i;
            checked[count][1]=y;
            count++;
        }
        if(sudoku[x][i]==0 && sudokuCheck[x][i][num]==0)
        {
            sudokuCheck[x][i][num]=1;
            sudokuCheck[x][i][0]++;
            checked[count][0]=x;
            checked[count][1]=i;
            count++;
        }
    }
    int sx,sy;
    sx=(x-1)/3;
    sy=(y-1)/3;
    for(int i=sx*3+1;i<sx*3+4;i++)
    {
        for(int j=sy*3+1;j<sy*3+4;j++)
        {
            if(sudoku[i][j]==0 && sudokuCheck[i][j][num]==0)
            {
                sudokuCheck[i][j][num]=1;
                sudokuCheck[i][j][0]++;
                checked[count][0]=i;
                checked[count][1]=j;
                count++;
            }
        }
    }
}

void backtracking(int x, int y, int cur)
{
    if(cur>=81 || sudokuZero[cur][0]==0)
    {
        finish=1;
        return;
    }
    int checked[27][2]={0};
    for(int i=1;i<=9;i++)
    {
        if(sudokuCheck[x][y][i]==0)
        {
            sudoku[x][y]=i;
            checkS(x,y,checked);
            int fx, fy;
            fx=sudokuZero[cur+1][0];
            fy=sudokuZero[cur+1][1];

            backtracking(fx,fy, cur+1);
            if(finish)
            {
                return;
            }
            int count=0;
            while(true)
            {
                int x1,y1;
                
                x1=checked[count][0];
                y1=checked[count][1];
                if(x1==0)
                {
                    break;
                } 
                sudokuCheck[x1][y1][i]=0;
                sudokuCheck[x1][y1][0]--;
                checked[count][0]=0;
                checked[count][1]=0;
                count++;
               
            }
            sudoku[x][y]=0;
            
        }
        
    }
    return;
    
}

int main()
{
    int checked[27][2]={0};
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cin>>sudoku[i][j];
        }
    }
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(sudoku[i][j]==0)
            {
                continue;
            }
            checkS(i, j, checked);
        }
    }
    int isFilled=1;
    int isZero=0;
    while(isFilled)
    {
        isFilled=0;
        isZero=0;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                if(sudokuCheck[i][j][0]==8 && sudoku[i][j]==0)
                {
                    for(int k=1;k<=9;k++)
                    {
                        if(sudokuCheck[i][j][k]==0)
                        {
                            sudoku[i][j]=k;
                            checkS(i, j, checked);
                            isFilled=1;
                            break;
                        }
                    }
                }
                if(sudoku[i][j]==0)
                {
                    isZero=1;
                }
            }
        }
    }

    if(isZero)
    {
        int count=0;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                if(sudoku[i][j]==0)
                {
                    sudokuZero[count][0]=i;
                    sudokuZero[count][1]=j;
                    count++;
                }
            }
        }
        int fx,fy;
        fx=sudokuZero[0][0];
        fy=sudokuZero[0][1];
        backtracking(fx, fy, 0);
    }

    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        if(i==9)
        {
            break;
        }
        cout<<"\n";
    }
}