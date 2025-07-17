#include <iostream>
#include <algorithm>

using namespace std;

long long makeSum(int n, int num)
{
    long long sumN=0;
    for(int i=1;i<=min(n,num);i++)
    {
        sumN+=min(n,(num/i));
    }
    return sumN;
}

int binarySearch(int n, int k, int l, int r)
{
    if(l>r) return l;
    int mid = (l+r)/2;
    long long sumN=makeSum(n,mid);
    if(sumN<k) return binarySearch(n,k,mid+1,r);
    sumN=makeSum(n,mid-1);
    if(sumN>=k) return binarySearch(n,k,l,mid-1);
    else return mid; 
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<binarySearch(n,k,1,1000000000);
}