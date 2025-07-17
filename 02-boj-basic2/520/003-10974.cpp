#include <iostream>

using namespace std;

void print(int *arr,int n, int now);

int main()
{
    int n;
    cin>>n;
    int arr[8]={0};
    print(arr, n, 0);
}

void print(int *arr,int n, int now)
{
    if(n==now)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        int skip=0;
        for(int j=0;j<now;j++)
        {
            if(arr[j]==i)
            {
                skip=1;
                break;
            }
        }
        if(skip)
        {
            continue;
        }
        arr[now]=i;
        print(arr, n, now+1);
    }
}