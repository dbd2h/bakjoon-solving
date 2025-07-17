#include <iostream>

using namespace std;

int main()
{
    int c;
    cin>>c;
    int arr[c][c]={0};
    cin>>arr[0][0];
    for(int i=1;i<c;i++)
    {
        for(int j=0;j<=i;j++)
        {
            int num;
            cin>>num;
            if(j==0)
            {
                arr[i][j]=arr[i-1][j]+num;
                continue;
            }
            if(j==i)
            {
                arr[i][j]=arr[i-1][j-1]+num;
                continue;
            }
            if(arr[i-1][j-1]>arr[i-1][j])
            {
                arr[i][j]=num+arr[i-1][j-1];
            }
            else
            {
                arr[i][j]=num+arr[i-1][j];
            }
        }
    }
    int max=-1;
    for(int i=0;i<c;i++)
    {
        if(arr[c-1][i]>max)
        {
            max=arr[c-1][i];
        }
    }
    cout<<max;
}