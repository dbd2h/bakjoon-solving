#include <iostream>

using namespace std;

void print(int count, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int i, int n);

int main()
{
    int n,i;
    cin>>n>>i;
    print(0,0,0,0,0,0,0,0,0,i,n);
}

void print(int count, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int i, int n)
{
    int arr[8]={n1, n2, n3, n4, n5, n6, n7, n8};
    if(count>=i)
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
        int k=0;
        for(;k<count;k++)
        {
            if(arr[k]==j)
                break;
        }
        if(k<count)
            continue;
        arr[count]=j;
        print(count+1, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], i, n);
    }
}