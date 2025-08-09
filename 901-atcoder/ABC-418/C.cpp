#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int l, int r, int tea[], int b)
{
    if(l>r) return -1;
    int middle=(l+r)/2;
    if(tea[middle]>=b)
    {
        if(middle==0 || tea[middle-1]<b) return middle;
        else return binarySearch(l,middle-1,tea,b);
    }
    else return binarySearch(middle+1,r,tea,b);
}


int main()
{
    int n,q;
    cin>>n>>q;
    int tea[300000]={0};
    long long sumT[300000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>tea[i];
    }
    sort(tea,tea+n);
    sumT[0]=tea[0];
    for(int i=1;i<n;i++)
    {
        sumT[i]=sumT[i-1]+tea[i];
    }
    for(int i=0;i<q;i++)
    {
        long long b;
        cin>>b;
        if(b>tea[n-1])
        {
            cout<<-1<<"\n";
            continue;
        }
        long long res=0;
        long long idx=binarySearch(0,n-1,tea,b);
        if(idx!=0) res+=sumT[idx-1];
        res+=((long long)n-idx)*(b-1);
        res+=1;
        cout<<res<<"\n";
    }
}