#include <iostream>

#define div 1'000'000'009

using namespace std;

int main()
{
    int len;
    cin>>len;
    int result[len];
    int max=-1;
    for(int i=0;i<len;i++)
    {
        cin>>result[i];
        if(max<result[i])
            max=result[i];
    }
    long long arr[max+1]={0};
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<=max;i++)
    {
        arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%div;
    }
    for(int i=0;i<len;i++)
    {
        cout<<arr[result[i]]<<"\n";
    }
}