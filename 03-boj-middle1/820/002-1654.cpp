#include <iostream>

using namespace std;

long long arr[10000]={0};

long long binarySearch(long long l, long long r, int k, int n)
{
    if(l>=r)return r;
    long long tot=0;
    long long tot2=0;
    long long middle=(l+r)/2;

    for(int i=0;i<k;i++)
    {
        tot+=arr[i]/middle;
        tot2+=arr[i]/(middle+1);
    }
    if(tot>=n && tot2<n) return middle;
    else if(tot>=n) return binarySearch(middle+1,r, k, n);
    else return binarySearch(l,middle,k,n);
}

int main()
{
    int k,n;
    cin>>k>>n;
    long long sum=0;
    for(int i=0;i<k;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<binarySearch(1,sum/n,k,n);
}