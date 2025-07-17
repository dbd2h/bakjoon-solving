#include <iostream>

using namespace std;

int binarySearch(int l, int r, int arr[], int n, int m)
{
    if(l>=r) return r;
    int middle=(l+r)/2;
    int middle2=middle-1;
    int c=0;
    int c2=0;
    int m1=1;
    int m2=1;
    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        if(middle<num) return binarySearch(middle+1,r,arr,n,m);
        else if(middle2<num) m2=-1;
        c+=num;
        c2+=num;
        if(c>middle)
        {
            c=num;
            m1++;
        }
        if(m2!=-1 && c2>middle2)
        {
            c2=num;
            m2++;
        }
    }
    if(m1<=m && (m2>m || m2==-1)) return middle;
    else if(m1>m) return binarySearch(middle+1,r,arr,n,m);
    else return binarySearch(l,middle-1,arr,n,m);
}

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[100000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<binarySearch(1,100000000,arr,n,m);
}