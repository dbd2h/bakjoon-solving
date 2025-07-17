#include <iostream>

using namespace std;

void print(int *arr, int n, int i, int count, int now);

int main()
{
    int n,i;
    cin>>n>>i;

    int arr[8]={0};

    print(arr, n, i, 0, 1);
}

void print(int *arr, int n, int i, int count, int now)
{
    if(count==i)
    {
        for(int j=0;j<i;j++)
        {
            cout<<arr[j]<<" ";
        }
        cout<<"\n";
        return;
    }
    if(now>n)
    {
        return;
    }
    for(int j=now;j<=n;j++)
    {
        arr[count]=j;
        print(arr, n, i, count+1, j+1);
    }
}