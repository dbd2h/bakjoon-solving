#include <iostream>

using namespace std;

int arr[1000000]={0};

int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int pl,de;
    pl=0;
    de=0;
    int minV=0;
    int sumV=0;
    while(true)
    {
        if(pl==n && sumV<s)
        {
            break;
        }
        if(sumV<s)
        {
            sumV+=arr[pl];
            pl++;
        }
        else if(sumV>=s)
        {
            if(minV==0 || minV>(pl-de)) minV=pl-de;
            sumV-=arr[de];
            de++;
        }
    }
    cout<<minV;
}