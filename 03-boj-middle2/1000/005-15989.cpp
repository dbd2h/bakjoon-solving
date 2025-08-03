#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    long long arr[10001]={0};
    int LEN=10000;
    for(int i=0;i<=LEN;i++)
    {
        arr[i]=1;
    }
    for(int i=0;i<LEN-1;i++)
    {
        arr[i+2]+=arr[i];
    }
    for(int i=0;i<LEN-2;i++)
    {
        arr[i+3]+=arr[i];
    }
    for(int i=0;i<t;i++)
    {
        int num;
        cin>>num;
        cout<<arr[num]<<"\n";
    }
}