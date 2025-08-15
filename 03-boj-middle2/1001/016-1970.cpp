#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[1000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int bit[1000][1000]={0};
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int l=j;
            int r=j+i;
            if(r>=n) break;
            int num=arr[r];
            int maxV=bit[l][r-1];
            for(int k=l;k<r;k++)
            {
                if(arr[k]!=arr[r]) continue;
                int sumV=1;
                if(r-l==1)
                {
                    sumV=1;
                }
                else if(k==l)
                {
                    sumV+=bit[k+1][r-1];
                }
                else if(k==r-1)
                {
                    sumV+=bit[l][k-1];
                }
                else
                {
                    sumV+=(bit[k+1][r-1]+bit[l][k-1]);
                }
                if(maxV<sumV)maxV=sumV;
            }
            bit[l][r]=maxV;
        }
    }
    cout<<bit[0][n-1];
}