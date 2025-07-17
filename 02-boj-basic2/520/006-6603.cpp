#include <iostream>

using namespace std;

void print(int *arr, int *nArr, int k, int count, int c);
void insert_sort(int *arr, int len);

int main()
{
    int k;
    cin>>k;
    while(k!=0)
    {
        int s[6];
        int numArr[k];
        for(int i=0;i<k;i++)
        {
            cin>>numArr[i];
        }
        insert_sort(numArr,k);
        print(s, numArr, k, 0, 0);
        cin>>k;
        if(k!=0)
        {
            cout<<"\n";
        }
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

void print(int *arr, int *nArr, int k, int count, int c)
{
    if(count!=6&&c>=k)
    {
        return;
    }
    if(count==6)
    {
        for(int i=0;i<6;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=c;i<k;i++)
    {
        arr[count]=nArr[i];
        print(arr, nArr, k, count+1, i+1);
    }
}