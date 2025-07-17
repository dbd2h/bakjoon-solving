#include <iostream>

using namespace std;

int main()
{
    int arr[9];
    int tot=0;
    int a,b;
    for(int i=0;i<9;i++)
    {
        cin>>arr[i];
        tot+=arr[i];
    }
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(tot-arr[i]-arr[j]==100)
            {
                a=i;
                b=j;
                break;
            }
        }
    }
    int res[7];
    int j=0;
    for(int i=0;i<9;i++)
    {
        if(i!=a&&i!=b)
        {
            res[j]=arr[i];
            j++;
        }
    }
    for(int i=0;i<7;i++)
    {
        for(int j=i+1;j<7;j++)
        {
            if(res[i]>res[j])
            {
                int c=res[i];
                res[i]=res[j];
                res[j]=c;
            }
        }
        cout<<res[i]<<"\n";
    }
}