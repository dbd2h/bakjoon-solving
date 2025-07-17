#include <iostream>

using namespace std;

int main()
{
    int c;
    cin>>c;
    int arr[c+1]={0};
    int res[c+1][2]={0};
    for(int i=1;i<=c;i++)
    {
        cin>>arr[i];
    }
    int max=arr[1];
    for(int i=1;i<=c;i++)
    {
        if(arr[i]<0)
        {
            if(res[i-1][0]+arr[i]<0)
            {
                res[i][0]=0;
            }
            else
            {
                res[i][0]=res[i-1][0]+arr[i];
            }
            if(res[i-1][0]>res[i-1][1]+arr[i])
            {
                res[i][1]=res[i-1][0];
            }
            else
            {
                res[i][1]=res[i-1][1]+arr[i];
            }
        }
        else
        {
            res[i][0]=res[i-1][0]+arr[i];
            res[i][1]=res[i-1][1]+arr[i];
            if(res[i][1]>max)
            {
                max=res[i][1];
            }
        }
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<max;
}