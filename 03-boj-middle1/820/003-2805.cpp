#include <iostream>

using namespace std;

int arr[1000000]={0};

int dif(int a, int b)
{
    if(a<b) return 0;
    return a-b;
}

int binarySearch(int l, int r, int n, int m)
{
    if(l>=r) return r;
    int middleH=(l+r)/2;
    long long tot=0;
    long long tot2=0;
    for(int i=0;i<n;i++)
    {
        tot+=dif(arr[i], middleH);
        tot2+=dif(arr[i],middleH+1);
    }
    if(tot>=m && tot2<m) return middleH;
    else if(tot<m) return binarySearch(l,middleH-1,n,m);
    else return binarySearch(middleH+1,r,n,m);
}

int main()
{
    int n ,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<binarySearch(0,1000000000,n,m);
}