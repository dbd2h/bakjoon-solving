#include <iostream>

using namespace std;

long long matrix[40][5][5]={0};

long long result[5][5]={0};

long long MOD=1000;

bool isF=true;

void matrixMaker(int a, int idx)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            long long n=0;
            for(int k=0;k<a;k++)
            {
                n+=matrix[idx-1][i][k]*matrix[idx-1][k][j];
            }
            n%=MOD;
            matrix[idx][i][j]=n;
        }
    }
}

void matrixPow(int a, long long b, int idx)
{
    if(b==0) return;
    if(idx==0)
    {
        matrixPow(a,b/2,idx+1);
    }
    else
    {
        matrixMaker(a,idx);
        matrixPow(a,b/2,idx+1);
    }
    if(b%2==0) return;
    if(isF)
    {
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<a;j++)
            {
                result[i][j]=matrix[idx][i][j];
            }
        }
        isF=false;
        return;
    }
    long long resultSave[5][5]={0};
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            long long n=0;
            for(int k=0;k<a;k++)
            {
                n+=result[i][k]*matrix[idx][k][j];
            }
            n%=MOD;
            resultSave[i][j]=n;
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            result[i][j]=resultSave[i][j];
        }
    }
    return;
}

int main()
{
    int a;
    long long b;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            cin>>matrix[0][i][j];
            matrix[0][i][j]%=MOD;
        }
    }
    matrixPow(a,b,0);
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}