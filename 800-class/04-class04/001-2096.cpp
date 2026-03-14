#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int maxDp[2][3];
    int minDp[2][3];
    for(int i=0;i<3;i++)
    {
        int num;
        cin>>num;
        maxDp[0][i]=num;
        minDp[0][i]=num;
        maxDp[1][i]=0;
        minDp[1][i]=1e9;
    }
    int resMax=0;
    int resMin=1e9;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            int num;
            cin>>num;
            for(int k=-1;k<=1;k++)
            {
                if(j+k<0 || j+k>=3) continue;
                maxDp[1][j]=max(maxDp[1][j],num+maxDp[0][j+k]);
                minDp[1][j]=min(minDp[1][j],num+minDp[0][j+k]);
            }
        }
        for(int j=0;j<3;j++)
        {
            maxDp[0][j]=maxDp[1][j];
            minDp[0][j]=minDp[1][j];
            maxDp[1][j]=0;
            minDp[1][j]=1e9;
        }
    }
    for(int i=0;i<3;i++)
    {
        resMax=max(resMax,maxDp[0][i]);
        resMin=min(resMin,minDp[0][i]);
    }
    cout<<resMax<<" "<<resMin;
}