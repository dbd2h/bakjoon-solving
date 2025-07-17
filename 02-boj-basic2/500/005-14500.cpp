#include <iostream>

using namespace std;

int bigRet(int l,int r);

int main()
{
    int r,c;
    cin>>r>>c;
    int numArr[r][c]={0};
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>numArr[i][j];
        }
    }
    int max=0;
    int tot;
    int pR,pC;
    for(int i=0;i<r-1;i++)
    {
        for(int j=0;j<c-1;j++)
        {
            tot=numArr[i][j]+numArr[i+1][j]+numArr[i][j+1]+numArr[i+1][j+1];
            max=bigRet(max,tot);
        }
        for(int j=0;j<c-2;j++)
        {
            //2x3
            tot=numArr[i][j+2]+numArr[i+1][j]+numArr[i+1][j+1]+numArr[i+1][j+2]; // ㅢ
            max=bigRet(max,tot);
            tot=numArr[i][j+1]+numArr[i+1][j]+numArr[i+1][j+1]+numArr[i+1][j+2]; //ㅗ
            max=bigRet(max,tot);
            tot=numArr[i][j+1]+numArr[i][j+2]+numArr[i+1][j]+numArr[i+1][j+1]; //_ㅣ-
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i+1][j]+numArr[i+1][j+1]+numArr[i+1][j+2]; //ㄴ
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i][j+1]+numArr[i+1][j+1]+numArr[i+1][j+2]; //ㄹ
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i][j+1]+numArr[i][j+2]+numArr[i+1][j+2]; //ㄱ
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i][j+1]+numArr[i][j+2]+numArr[i+1][j+1]; //ㅜ
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i][j+1]+numArr[i][j+2]+numArr[i+1][j]; //ㅣ-
            max=bigRet(max,tot);
        }
    }
    for(int i=0;i<r-2;i++)
    {
        for(int j=0;j<c-1;j++)
        {
            tot=numArr[i+2][j]+numArr[i][j+1]+numArr[i+1][j+1]+numArr[i+2][j+1]; // ㅢ
            max=bigRet(max,tot);
            tot=numArr[i+1][j]+numArr[i][j+1]+numArr[i+1][j+1]+numArr[i+2][j+1]; //ㅗ
            max=bigRet(max,tot);
            tot=numArr[i+1][j]+numArr[i+2][j]+numArr[i][j+1]+numArr[i+1][j+1]; //_ㅣ-
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i][j+1]+numArr[i+1][j+1]+numArr[i+2][j+1]; //ㄴ
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i+1][j]+numArr[i+1][j+1]+numArr[i+2][j+1]; //ㄹ
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i+1][j]+numArr[i+2][j]+numArr[i+2][j+1]; //ㄱ
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i+1][j]+numArr[i+2][j]+numArr[i+1][j+1]; //ㅜ
            max=bigRet(max,tot);
            tot=numArr[i][j]+numArr[i+1][j]+numArr[i+2][j]+numArr[i][j+1]; //ㅣ-
            max=bigRet(max,tot);
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c-3;j++)
        {
            tot=numArr[i][j]+numArr[i][j+1]+numArr[i][j+2]+numArr[i][j+3];
            max=bigRet(max,tot);
        }
    }
    for(int i=0;i<r-3;i++)
    {
        for(int j=0;j<c;j++)
        {
            tot=numArr[i][j]+numArr[i+1][j]+numArr[i+2][j]+numArr[i+3][j];
            max=bigRet(max,tot);
        }
    }
    cout<<max;
}

int bigRet(int l,int r)
{
    if(l>r)
    {
        return l;
    }
    else
    {
        return r;
    }
}