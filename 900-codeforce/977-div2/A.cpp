#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        long long arr[50]={0};
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int num=(arr[0]+arr[1])/2;
        for(int i=2;i<n;i++)
        {
            num+=arr[i];
            num/=2;
        }
        cout<<num<<"\n";
    }
}