#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long dp[100][100]={0};
    dp[0][0]=1;
    long long arr[100][100]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0) continue;
            if(!dp[i][j]) continue;
            if(i+arr[i][j]<n) dp[i+arr[i][j]][j]+=dp[i][j];
            if(j+arr[i][j]<n) dp[i][j+arr[i][j]]+=dp[i][j];
            
        }
    }
    
    cout<<dp[n-1][n-1];
}