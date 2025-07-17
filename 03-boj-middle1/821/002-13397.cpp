#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int n, int m)
{
    int middle1=(l+r)/2;
    int c=1;
    int max=0;
    int min=10001;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i]) max=arr[i];
        if(min>arr[i]) min=arr[i];
        if(max-min>middle1)
        {
            c++;
            max=arr[i];
            min=arr[i];
            continue;
        }
    }
    if(c>m) return binarySearch(arr, middle1+1, r, n, m);
    c=1;
    max=0;
    min=10001;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i]) max=arr[i];
        if(min>arr[i]) min=arr[i];
        if(max-min>middle1-1)
        {
            c++;
            max=arr[i];
            min=arr[i];
        }
    }
    if(c>m) return middle1;
    return binarySearch(arr,l,middle1-1,n,m);
}

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[5000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<binarySearch(arr,0,10000,n,m);
}