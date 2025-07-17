#include <iostream>
#include <algorithm>

using namespace std;

int house[200000]={0};

int binarySearch(int l, int r, int n, int c)
{
    if(l>=r)
    {
        return r;
    }
    int middle=(l+r)/2;
    int middleN=middle+1;
    int curC=1;
    int nextC=1;
    int curSum=0;
    int nextSum=0;
    for(int i=1;i<n;i++)
    {
        curSum+=(house[i]-house[i-1]);
        nextSum+=(house[i]-house[i-1]);
        if(curSum>=middle)
        {
            curC++;
            curSum=0;
        }
        if(nextSum>=middleN)
        {
            nextC++;
            nextSum=0;
        }
    }
    if(curC>=c && nextC<c) return middle;
    else if(curC<c) return binarySearch(l, middle-1, n, c);
    else return binarySearch(middle+1,r,n,c);
}

int main()
{
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        cin>>house[i];
    }
    sort(house, house+n);
    int interval=(house[n-1]-house[0])/(c-1);
    interval=binarySearch(1, interval, n, c);
    cout<<interval;
}

