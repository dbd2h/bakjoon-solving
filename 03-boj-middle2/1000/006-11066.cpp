#include <iostream>

using namespace std;

void problem()
{
    int n;
    cin>>n;
    long long dp[500][500]={0};
    for(int i=0;i<n;i++)
    {
        cin>>dp[i][i];
        int sum=dp[i][i];
        for(int j=i-1;j>=0;j--)
        {
            sum+=dp[j][j];
            for(int l=j;l<=i-1;l++)
            {
                int r=l+1;
                int dpV=sum;
                if(j!=l) dpV+=dp[j][l];
                if(r!=i) dpV+=dp[r][i];
                if(dp[j][i]==0 || dp[j][i]>dpV) dp[j][i]=dpV;
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();
    }
}
