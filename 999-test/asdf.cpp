#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int table[15][15]={0};
    int ox,oy;
    ox=(k-1)/m+1;
    oy=(k-1)%m+1;
    for(int i=0;i<n;i++)
    {
        table[i][0]=1;
    }
    for(int i=0;i<m;i++)
    {
        table[0][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            table[i][j]=table[i-1][j]+table[i][j-1];
        }
    }
    if(k==0)
    {
        cout<<table[n-1][m-1];
        return 0;
    }
    int result;
    result=table[ox-1][oy-1]*table[n-ox][m-oy];
    cout<<result;
}