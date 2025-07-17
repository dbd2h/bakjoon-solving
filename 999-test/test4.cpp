#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[100]={0};
    int bit[50001]={0};
    bit[0]=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr, arr+n);
    for(int i=0;i<n;i++)
    {
        for(int j=500*i;j>=0;j--)
        {
            if(bit[j]==1) bit[j+arr[i]]=1;
        }   
    }
    int result=50000;
    for(int i=0;i<50001;i++)
    {
        if(bit[i]==0) continue;
        int v=max(sum-i, i*2);
        if(v<result) result=v;
        else break;
    }
    cout<<result;
}
