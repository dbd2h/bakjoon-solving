#include <iostream>

using namespace std;

void print(int *arr, int *numA, int n, int i, int count);

void insert_sort(int *arr, int len);

int main()
{
    int n,i;
    int arr[7];
    int numArr[7];

    cin>>n>>i;
    for(int j=0;j<n;j++)
    {
        cin>>numArr[j];
    }
    insert_sort(numArr,n);
    print(arr, numArr, n, i, 0);
}

void print(int *arr, int *numA, int n, int i, int count)
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
    for(int j=0;j<n;j++)
    {
        arr[count]=numA[j];
        print(arr,numA,n,i,count+1);
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
        arr[i]=arr[minI];
        arr[minI]=c;
    }
}