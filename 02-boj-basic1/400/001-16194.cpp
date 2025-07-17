#include <iostream>

using namespace std;

int main()
{
    int n;
    int price[10000]={0};
    int arr[10000]={0};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int min=-1;
        cin>>price[i];
        for(int j=i;j>=1;j--)
        {
            if(min==-1)
            {
                min=price[j];
                continue;
            }

            if((arr[i-j]+price[j])<min)
                min=arr[i-j]+price[j];
        }
        arr[i]=min;
    }
    cout<<arr[n];
}