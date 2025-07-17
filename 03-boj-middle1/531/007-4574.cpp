#include <iostream>
#include <string>

using namespace std;

int domino[10][10]={0};
int sudoku[10][10]={0};
int isZeros[81][2]={0};
int finish=0;

int check(int x, int y, int n)
{
    for(int i=1;i<=9;i++)
    {
        if(sudoku[x][i]==n)
        {
            return 0;
        }
        if(sudoku[i][y]==n)
        {
            return 0;
        }
    }
    int x1=(x-1)/3;
    int y1=(y-1)/3;
    for(int i=x1*3+1;i<x1*3+4;i++)
    {
        for(int j=y1*3+1;j<y1*3+4;j++)
        {
            if(sudoku[i][j]==n)
            {
                return 0;
            }
        }
    }
    return 1;
}

void backtracking(int count)
{
    int x,y;
    x=isZeros[count][0];
    y=isZeros[count][1];
    if(count>=81 || x==0)
    {
        finish=1;
        return;
    }
    if(sudoku[x][y]!=0)
    {
        backtracking(count+1);
        return;
    }
    for(int i=1;i<=9;i++)
    {
        if(check(x,y,i))
        {
            sudoku[x][y]=i;
            if(x+1<=9 && sudoku[x+1][y]==0)
            {
                
                for(int j=1;j<=9;j++)
                {
                    
                    if(domino[i][j]==1)
                    {
                        continue;
                    }
                    if(check(x+1,y,j))
                    {
                        sudoku[x+1][y]=j;
                        domino[i][j]=1;
                        domino[j][i]=1;
                        backtracking(count+1);
                        if(finish==1)
                        {
                            return;
                        }
                        sudoku[x+1][y]=0;
                        domino[i][j]=0;
                        domino[j][i]=0;
                    }
                }
            }
            
            if(y+1<=9 && sudoku[x][y+1]==0)
            {
                for(int j=1;j<=9;j++)
                {
                    if(domino[i][j]==1)
                    {
                        continue;
                    }
                    if(check(x,y+1,j))
                    {
                        sudoku[x][y+1]=j;
                        domino[i][j]=1;
                        domino[j][i]=1;
                        backtracking(count+1);
                        if(finish==1)
                        {
                            return;
                        }
                        sudoku[x][y+1]=0;
                        domino[i][j]=0;
                        domino[j][i]=0;
                    }
                }
            }
            sudoku[x][y]=0;
        }
    }
    return;
}

int main()
{
    int puzzle=1;
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
        {
            break;
        }

        for(int i=1;i<=9;i++)
        {
            domino[i][i]=1;
        }
        
        int a,b;
        string posA, posB;
        for(int i=0;i<n;i++)
        {
            
            cin>>a>>posA>>b>>posB;
            domino[a][b]=1;
            domino[b][a]=1;
            int xA=posA[0]-'A'+1;
            int yA=posA[1]-'0';
            sudoku[xA][yA]=a;
            int xB=posB[0]-'A'+1;
            int yB=posB[1]-'0';
            sudoku[xB][yB]=b;
        }
        for(int i=1;i<=9;i++)
        {
            cin>>posA;
            int x=posA[0]-'A'+1;
            int y=posA[1]-'0';
            sudoku[x][y]=i;
        }
        int count=0;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                if(sudoku[i][j]==0)
                {
                    isZeros[count][0]=i;
                    isZeros[count][1]=j;
                    count++;
                }
            }
        }
        backtracking(0);
        cout<<"Puzzle "<<puzzle<<"\n";
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                cout<<sudoku[i][j];
            }
            cout<<"\n";
        }
        puzzle++;
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                domino[i][j]=0;
                sudoku[i][j]=0;
            }
        }
        for(int i=0;i<81;i++)
        {
            isZeros[i][0]=0;
            isZeros[i][1]=0;
        }
        finish=0;
    }
}
