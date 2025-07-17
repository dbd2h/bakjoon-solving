#include <iostream>

using namespace std;

int oven[300000]={0};
int pizza[300000]={0};

int binarySearch(int l, int r, int d, int s)
{
    if(l>r) return l;
    int middle=(l+r)/2;
    if(oven[middle]<s) return binarySearch(middle+1, r, d, s);
    else if(oven[middle]>=s && middle+1!=d && oven[middle+1]>=s) return binarySearch(l,middle-1,d,s);
    else  return middle;
}

int main()
{
    int d,n;
    cin>>d>>n;
    for(int i=0;i<d;i++)
    {
        cin>>oven[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>pizza[i];
    }
    int s=oven[0];
    for(int i=1;i<d;i++)
    {
        if(oven[i]>s) oven[i]=s;
        else if(oven[i]<s) s=oven[i];
    }
    cout<<binarySearch(0,d,d,3);
}