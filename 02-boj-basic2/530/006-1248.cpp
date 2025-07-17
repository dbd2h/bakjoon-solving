#include <iostream>

using namespace std;

void guess(int *arr, char (*s)[10], int n, int count, int *isFinish);

int main()
{
    int n;
    cin>>n;
    char matrix[10][10];
    int arr[n];
    int finish=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    guess(arr, matrix, n, 0, &finish);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void guess(int *arr, char (*s)[10], int n, int count, int *isFinish)
{
    if(count==n)
    {
        *isFinish=1;
        return;
    }
    for(int i=1;i<=10;i++)
    {
        if(s[count][count]=='0')
        {
            arr[count]=0;
            guess(arr,s,n,count+1, isFinish);
            return;
        }
        int skip=0;
        int num=i;
        int tot;
        if(s[count][count]=='-')
        {
            num=-i;
        }
        tot=num;
        for(int j=0;j<count;j++)
        {
            tot+=arr[count-j-1];
            if(s[count-j-1][count]=='+'&&tot<=0)
            {
                skip=1;
                break;
            }
            else if(s[count-j-1][count]=='-'&&tot>=0)
            {
                skip=1;
                break;
            }
            else if(s[count-j-1][count]=='0'&&tot!=0)
            {
                skip=1;
                break;
            }
        }
        if(skip==0)
        {
            arr[count]=num;
            guess(arr, s, n, count+1, isFinish);
            if(*isFinish==1)
            {
                return;
            }
        }
    }
}