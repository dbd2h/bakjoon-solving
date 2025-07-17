#include <iostream>

using namespace std;

void maxMaker(int *arr, int *nArr, int n, int count, int *max);

int sub(int n1, int n2);

int main()
{
    int n;
    int max=0;
    cin>>n;
    int numArr[n];
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>numArr[i];
    }
    maxMaker(arr,numArr,n,0,&max);
    cout<<max;
}   

void maxMaker(int *arr, int *nArr, int n, int count, int *max)
{
    if(count==n)
    {
        int m=0;
        for(int i=0;i<count-1;i++)
        {
            m+=sub(nArr[arr[i]],nArr[arr[i+1]]);
        }
        if(m>*max)
        {
            *max=m;
        }
        return;
    }
    for(int i=0;i<n;i++)
    {
        int skip=0;
        for(int j=0;j<count;j++)
        {
            if(arr[j]==i)
            {
                skip=1;
                break;
            }
        }
        if(skip==1)
        {
            continue;
        }
        arr[count]=i;
        maxMaker(arr, nArr, n, count+1, max);
    }
}

int sub(int n1, int n2)
{
    if(n1-n2>0)
    {
        return n1-n2;
    }
    else
    {
        return n2-n1;
    }
}