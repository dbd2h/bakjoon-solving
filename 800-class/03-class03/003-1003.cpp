#include <iostream>

using namespace std;

void fibonacci(int n, long long dp0[], long long dp1[])
{
    if(n==0)
    {
        dp0[n]=1;
        dp1[n]=0;
        return;
    }
    if(n==1)
    {
        dp0[n]=0;
        dp1[n]=1;
        return;
    }
    if(dp0[n-1]==-1) fibonacci(n-1,dp0,dp1);
    if(dp0[n-2]==-1) fibonacci(n-2,dp0,dp1);
    dp0[n]=dp0[n-1]+dp0[n-2];
    dp1[n]=dp1[n-1]+dp1[n-2];
    return;
}

int main()
{
    long long dp0[41];
    long long dp1[41];
    for(int i=0;i<=40;i++)
    {
        dp0[i]=-1;
        dp1[i]=-1;
    }
    fibonacci(40,dp0,dp1);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        cout<<dp0[m]<<" "<<dp1[m]<<"\n";
    }
}