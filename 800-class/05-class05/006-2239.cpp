#include <iostream>
#include <string>

using namespace std;

bool makeSudoku(int sudoku[10][10], bool rowCheck[10][10], bool colCheck[10][10], bool blockCheck[10][10], int idx)
{
    if(idx>81) return true;
    int x=(idx-1)/9+1;
    int y=(idx-1)%9+1;
    if(sudoku[x][y]!=0)
    {
        if(makeSudoku(sudoku,rowCheck,colCheck,blockCheck,idx+1)) return true;
        return false;
    }
    for(int i=1;i<=9;i++)
    {
        if(rowCheck[x][i] || colCheck[y][i] || blockCheck[((x-1)/3)*3+(y-1)/3+1][i]) continue;
        rowCheck[x][i]=1;
        colCheck[y][i]=1;
        blockCheck[((x-1)/3)*3+(y-1)/3+1][i]=1;
        sudoku[x][y]=i;
        if(makeSudoku(sudoku,rowCheck,colCheck,blockCheck,idx+1)) return true;
        rowCheck[x][i]=0;
        colCheck[y][i]=0;
        blockCheck[((x-1)/3)*3+(y-1)/3+1][i]=0;
        sudoku[x][y]=0;
    }
    return false;
}

int main()
{
    int sudoku[10][10];
    bool rowCheck[10][10]={0};
    bool colCheck[10][10]={0};
    bool blockCheck[10][10]={0};
    for(int i=1;i<=9;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=9;j++)
        {
            int cur=s[j-1]-'0';
            sudoku[i][j]=cur;
            if(cur==0) continue;
            rowCheck[i][cur]=1;
            colCheck[j][cur]=1;
            blockCheck[((i-1)/3)*3+(j-1)/3+1][cur]=1;
        }
    }
    makeSudoku(sudoku,rowCheck,colCheck,blockCheck,1);
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cout<<sudoku[i][j];
        }
        cout<<"\n";
    }
}