#include<iostream>

using namespace std;

int main()
{
    int arr[100001]={0};
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int w,v;
        cin>>w>>v;
        for(int j=k-w;j>=0;j--)
        {
            if(!arr[j]) continue;
            if(arr[j+w]<arr[j]+v) arr[j+w]=arr[j]+v;
        }
        if(arr[w]<v) arr[w]=v;
    }
    int maxV=0;
    for(int i=0;i<=k;i++)
    {
        if(arr[i]>maxV) maxV=arr[i];
    }
    cout<<maxV;
}