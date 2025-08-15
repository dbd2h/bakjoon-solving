#include <iostream>

using namespace std;

long long matrix[65][2][2]={0};
long long result[2][2]={0};
long long MOD=1'000'000'007;
bool isF=true;

void fibo(long long n, int idx)
{
    if(n==0) return;
    if(idx==0) fibo(n/2,idx+1);
    else
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                long long a=0;
                for(int k=0;k<2;k++)
                {
                    a+=matrix[idx-1][i][k]*matrix[idx-1][k][j];
                }
                matrix[idx][i][j]=a;
                matrix[idx][i][j]%=MOD;
            }
        }
        fibo(n/2,idx+1);
    }
    if(n%2==0) return;
    if(isF)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                result[i][j]=matrix[idx][i][j];
            }
        }
        isF=false;
        return;
    }
    long long resultC[2][2]={0};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            long long a=0;
            for(int k=0;k<2;k++)
            {
                a+=result[i][k]*matrix[idx][k][j];
            }
            resultC[i][j]=a;
            resultC[i][j]%=MOD;
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            result[i][j]=resultC[i][j];
        }
    }
}


int main()
{
    long long n;
    cin>>n;
    matrix[0][0][0]=1;
    matrix[0][0][1]=1;
    matrix[0][1][0]=1;
    matrix[0][1][1]=0;
    fibo(n,0);
    cout<<result[0][1];
}