#include <iostream>

using namespace std;

void print(int *arr, int n, int i, int count);

int main()
{
    int n, i;
    cin>>n>>i;
    int numArr[7]={0};
    print(numArr, n, i, 0);
}

void print(int *arr, int n, int i, int count)
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
    for(int j=1;j<=n;j++)
    {
        arr[count]=j;
        print(arr, n, i, count+1);
    }
}