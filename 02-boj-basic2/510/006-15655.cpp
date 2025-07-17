#include <iostream>

using namespace std;

void print(int *arr, int *numA, int n, int i, int count, int c);

void bubble_sort(int *arr, int len);

int main()
{
    int n,i;
    int numArr[8]={0};
    int arr[8]={0};
    cin>>n>>i;
    for(int i=0;i<n;i++)
    {
        cin>>numArr[i];
    }
    bubble_sort(numArr, n);
    print(arr,numArr,n,i,0,0);
}

void print(int *arr, int *numA, int n, int i, int count, int c)
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
    if(c>=n)
    {
        return;
    }
    for(int j=c;j<n;j++)
    {
        arr[count]=numA[j];
        print(arr,numA,n,i,count+1,j+1);
    }
}

void bubble_sort(int *arr, int len)
{
    int min;
    int minI;
    for(int i=0;i<len;i++)
    {
        min=arr[i];
        minI=i;
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