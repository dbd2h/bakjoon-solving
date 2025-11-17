#include <iostream>
#include <algorithm>
#include <map>

#define LEN 2000

using namespace std;

int binarySearch(int l, int r, int dp[LEN][LEN][2], int diff, int L, int n)
{
    if(l>r) return -1;
    int middle=(l+r)/2;
    int middle2=(l+r)/2-1;
    if(dp[n][middle][0]<diff) return binarySearch(middle+1,r,dp,diff,L,n);
    else if(dp[n][middle][0]>diff) return binarySearch(l,middle-1,dp,diff,L,n);
    if(middle2>=L && dp[n][middle2][0]>=diff) return binarySearch(l,middle-1,dp,diff,L,n);
    else return middle;
}   

bool cmp(int n1, int n2)
{
    return n1<n2;
}

int main()
{
    int n;
    cin>>n;
    int arr[LEN];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n,cmp);
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    int dp[LEN][LEN][2]={0};
    int res=2;
    dp[n-2][n-1][0]=arr[n-1]-arr[n-2];
    dp[n-2][n-1][1]=2;
    for(int i=n-3;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            int diff=arr[j]-arr[i];
            int idx=binarySearch(j+1,n-1,dp,diff,j+1,j);
            if(idx==-1)
            {
                dp[i][j][0]=diff;
                dp[i][j][1]=2;
            }
            else
            {
                dp[i][j][0]=diff;
                dp[i][j][1]=dp[j][idx][1]+1;
            }
            if(dp[i][j][1]>res) res=dp[i][j][1];
        }
    }
    cout<<res;
}