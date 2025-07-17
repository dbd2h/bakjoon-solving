#include <iostream>

using namespace std;

void print(int *arr, int *numA, int n, int i, int count, int index);

void insert_sort(int *arr, int len);

int main()
{
    int n,i;
    int arr[8];
    int numArr[8];
    cin>>n>>i;
    for(int j=0;j<n;j++)
    {
        cin>>numArr[j];
    }
    insert_sort(numArr, n);
    print(arr,numArr,n,i,0,0);
}

void print(int *arr, int *numA, int n, int i, int count, int index)
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
    for(int j=index;j<n;j++)
    {
        arr[count]=numA[j];
        print(arr,numA,n,i,count+1,j);
    }
}

void insert_sort(int *arr, int len)
{
    for(int i=0;i<len;i++)
    {
        int min=arr[i];
        int minI=i;
        for(int j=i+1;j<len;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                minI=j;
            }
        }
        int c=arr[i];
        arr[i]=min;
        arr[minI]=c;
    }
}