#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(m+k-1>n || n>m*k)
    {
        cout<<-1;
        return 0;
    }

    int rem=n%m;
    int div=n/m;
    int downCount=div+(rem!=0);
    for(int i=n-m+1;i<=n;i++)
    {
        cout<<i<<" ";
    }
    for(int i=1;i<div+(rem!=0);i++)
    {
        if(downCount<k)
        {
            if(downCount+m-1<=k)
            {
                for(int j=n-m*i;j>n-m*(i+1);j--)
                {
                    if(j<=0) continue;
                    cout<<j<<" ";
                }
                downCount+=(m-1);
            }
            else if(downCount+m-1>k)
            {
                for(int j=n-m*(i+1)+1;j<n-m*(i+1)+1+m-(k-downCount+1);j++) // !!!!!
                {
                    if(j<=0) continue;
                    cout<<j<<" ";
                }
                for(int j=n-m*i;j>=n-m*(i+1)+1+m-(k-downCount+1);j--) // !!!!!!
                {
                    cout<<j<<" ";
                }
                downCount+=(m-1);
            }
        }
        else
        {
            for(int j=n-m*(i+1)+1;j<=n-m*i;j++)
            {
                if(j<=0) continue;
                cout<<j<<" ";
            }
        }
    }
}