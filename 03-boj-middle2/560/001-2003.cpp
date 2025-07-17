#include <iostream>

using namespace std;

int arr[10000]={0};

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int de,pl;
    de=0;
    pl=0;
    int res=0;
    int s=0;
    while(true)
    {
        if(pl==n && s<m) break;
        if(s<m)
        {
            s+=arr[pl];
            pl++;
        }
        else if(s>m)
        {
            s-=arr[de];
            de++;
        }
        else if(s==m)
        {
            res++;
            s-=arr[de];
            de++;
        }
    }
    cout<<res;
}