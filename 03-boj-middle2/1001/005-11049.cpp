#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int dp[500][500]={0};
    int matrix[500][2]={0};
    for(int i=0;i<n;i++)
    {
        int r,c;
        cin>>r>>c;
        matrix[i][0]=r;
        matrix[i][1]=c;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            int minV=-1;
            for(int l=j;l<i;l++)
            {
                int r=l+1;
                int sumV=dp[j][l]+dp[r][i]+matrix[j][0]*matrix[l][1]*matrix[i][1];
                if(minV==-1 || minV>sumV) minV=sumV;
            }
            dp[j][i]=minV;
        }
    }
    cout<<dp[0][n-1];
}