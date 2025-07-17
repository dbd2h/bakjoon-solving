#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int leftBig=-1;
    cin>>arr[0];
    for(int i=1;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i-1]>arr[i])
        {
            leftBig=i-1;
        }
    }
    int dif=10000;
    int index=leftBig;
    for(int i=leftBig+1;i<n;i++)
    {
        if(arr[leftBig]-arr[i]<0)
        {
            continue;
        }
        if(arr[leftBig]-arr[i]<dif)
        {
            dif=arr[leftBig]-arr[i];
            index=i;
        }
    }
    int c=arr[leftBig];
    arr[leftBig]=arr[index];
    arr[index]=c;

    if(leftBig==-1)
    {
        cout<<-1;
    }

    else
    {
        for(int i=leftBig+1;i<n;i++)
        {
            int max=arr[i];
            int maxI=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]>max)
                {
                    max=arr[j];
                    maxI=j;
                }
            }
            c=arr[i];
            arr[i]=max;
            arr[maxI]=c;
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}