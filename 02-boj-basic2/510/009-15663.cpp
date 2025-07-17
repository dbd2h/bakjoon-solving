#include <iostream>

using namespace std;

void print(int *arr, int *nArr, int *cArr, int index, int i, int count);

void insert_sort(int *arr, int len);

int main()
{
    int n,i;
    int arr[8];
    int nArr[8];
    int countArr[10001]={0};
    cin>>n>>i;
    int input;
    int index=0;
    for(int j=0;j<n;j++)
    {
        cin>>input;
        countArr[input]++;
        for(int k=0;k<j;k++)
        {
            if(nArr[k]==input)
            {
                input=0;
                break;
            }
        }
        if(input!=0)
        {
            nArr[index]=input;
            index++;
        }
    }
    insert_sort(nArr, index);
    print(arr,nArr,countArr,index,i,0);

}

void print(int *arr, int *nArr, int *cArr, int index, int i, int count)
{
    for(int j=0;j<index;j++)
    {
        if(count==i)
        {
            break;
        }
        if(cArr[nArr[j]]!=0)
        {
            arr[count]=nArr[j];
            cArr[nArr[j]]--;
            print(arr,nArr,cArr,index,i,count+1);
            cArr[nArr[j]]++;
        }
    }
    if(count==i)
    {
        for(int j=0;j<i;j++)
        {
            cout<<arr[j]<<" ";
        }
        cout<<"\n";
    }
    return;
}

void insert_sort(int *arr, int len)
{
    for(int i=0;i<len;i++)
    {
        int min=arr[i];
        int minI=i;
        for(int j=i+1;j<len;j++)
        {
            if(arr[j]<min)
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