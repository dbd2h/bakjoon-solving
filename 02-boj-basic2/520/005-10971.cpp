#include <iostream>

using namespace std;

void tsp(int *arr, int (*w)[10], int n, int count, int *min);

int main()
{
    int n;
    int min=10'000'000;
    cin>>n;
    int w[10][10];
    int arr[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>w[i][j];
        }
    }
    tsp(arr,w,n,0,&min);
    cout<<min;
}

void tsp(int *arr, int (*w)[10], int n, int count, int *min)
{
    if(count==n)
    {
        int m=0;
        for(int i=0;i<n;i++)
        {
            if(w[arr[i]][arr[(i+1)%n]]==0)
            {
                return;
            }
            m+=w[arr[i]][arr[(i+1)%n]];
        }
        if(*min>m)
        {
            *min=m;
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
        tsp(arr, w, n, count+1, min);
    }
}