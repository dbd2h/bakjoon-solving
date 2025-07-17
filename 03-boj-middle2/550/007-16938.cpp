#include <iostream>
#include <algorithm>

using namespace std;

int arr[15]={0};


void camp(int n, int l, int r, int x, int c, int *num, int s, int lx, int rx)
{
    if(n==c)
    {
        if(s>=l && s<=r && (rx-lx)>=x)
        {
            (*num)++;
        }
        return;
    }
    int curLX=lx;
    camp(n,l,r,x,c+1,num,s,lx,rx);
    if(lx==0)
    {
        camp(n,l,r,x,c+1,num,s+arr[c],arr[c],arr[c]);
    }
    else
    {
        camp(n,l,r,x,c+1,num,s+arr[c],lx,arr[c]);
    }
}

int main()
{
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    int result=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    camp(n,l,r,x,0,&result,0,0,0);
    cout<<result;
}