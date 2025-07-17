#include <iostream>

using namespace std;

void teamMaker(int *arr, int (*s)[20], int n, int count, int index, int *minDiff);

int sub(int a, int b);

int main()
{
    int n;
    int diff=-1;
    cin>>n;
    int s[20][20];
    int arr[n/2];
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

void teamMaker(int *arr, int (*s)[20], int n, int count, int index, int *minDiff)
{
    if(index>=n&&count!=n/2)
    {
        return;
    }
    if(count==n/2)
    {
        int a=0,b=0;
        int anoArr[n/2];
        int st1=0;
        int st2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[st1]==i)
            {
                st1++;
            }
            else
            {
                anoArr[st2]=i;
                st2++;
            }
        }
        for(int i=0;i<n/2;i++)
        {
            for(int j=i+1;j<n/2;j++)
            {
                a+=s[arr[i]][arr[j]];
                a+=s[arr[j]][arr[i]];
                b+=s[anoArr[i]][anoArr[j]];
                b+=s[anoArr[j]][anoArr[i]];
            }
        }
        if(sub(a,b)<*minDiff||*minDiff==-1)
        {
            *minDiff=sub(a,b);
        }
        return;
    }
    for(int i=index;i<n;i++)
    {
        arr[count]=i;
        teamMaker(arr, s, n, count+1, i+1, minDiff);
    }
}

int sub(int a, int b)
{
    if(a-b>0)
    {
        return a-b;
    }
    else
    {
        return b-a;
    }
}