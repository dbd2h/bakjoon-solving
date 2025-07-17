#include <iostream>

using namespace std;

void teamMaker(int *arr, int (*s)[20], int n, int count, int index, int *diff);

int sub(int n1, int n2);

int main()
{
    int n;
    cin>>n;
    int diff=-1;
    int arr[n];
    int s[20][20];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>s[i][j];
        }
    }
    teamMaker(arr, s, n, 0, 0, &diff);
    cout<<diff;

}

void teamMaker(int *arr, int (*s)[20], int n, int count, int index, int *diff)
{
    if(count==n)
    {
        return;
    }
    if(index==n)
    {
        int arr2[n];
        int index1=0;
        int tot1=0;
        int tot2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[index1]==i)
            {
                index1++;
            }
            else
            {
                arr2[i-index1]=i;
            }
        }
        for(int i=0;i<count;i++)
        {
            for(int j=i+1;j<count;j++)
            {
                tot1+=s[arr[i]][arr[j]];
                tot1+=s[arr[j]][arr[i]];
            }
        }
        for(int i=0;i<n-count;i++)
        {
            for(int j=i+1;j<n-count;j++)
            {
                tot2+=s[arr2[i]][arr2[j]];
                tot2+=s[arr2[j]][arr2[i]];
            }
        }
        
        int d=sub(tot1,tot2);
        if(d<*diff||*diff==-1)
        {
            *diff=d;
        }
        return;
    }
    for(int i=index;i<n;i++)
    {
        arr[count]=i;
        teamMaker(arr, s, n, count+1, i+1, diff);
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