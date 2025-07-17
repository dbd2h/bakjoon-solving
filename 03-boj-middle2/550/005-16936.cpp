#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100]={0};
long long chainArr[100]={0};

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        chainArr[i]=-1;
    }
    sort(arr, arr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]%3==0)
        {
            long long div=arr[i]/3;
            for(int j=0;j<n;j++)
            {
                if(div==arr[j])
                {
                    chainArr[i]=j;
                    break;
                }
            }
        }
        long long mul=arr[i]*2;
        for(int j=0;j<n;j++)
        {
            if(mul==arr[j])
            {
                chainArr[i]=j;
                break;
            }
        }
    }
    int start=0;
    int bit[100]={0};
    for(int i=0;i<n;i++)
    {
        if(chainArr[i]==-1) continue;
        bit[chainArr[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(bit[i]==0) start=i;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[start]<<" ";
        start=chainArr[start];
    }
}