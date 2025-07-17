#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[10]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int result=0;
    for(int i=n-1;i>=0;i--)
    {
        while(arr[i]<=k)
        {
            k-=arr[i];
            result++;
        }
    }
    cout<<result;
}