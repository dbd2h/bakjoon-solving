#include <iostream>

using namespace std;

int tArr[10001]={0};

long long amuse(int m, long long t)
{
    long long sumN=0;
    for(int i=1;i<=m;i++)
    {
        sumN+=(t/tArr[i]);
    }
    return sumN;
}

long long binarySearch(int n, int m, long long l, long long r)
{
    if(l>r) return l;
    long long t=(l+r)/2;
    long long sumN=amuse(m,t);
    if(sumN<n-m) return binarySearch(n,m,t+1,r);
    sumN=amuse(m,t-1);
    if(sumN<n-m) return t;
    else return binarySearch(n,m,l,t-1); 
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>tArr[i];
    }
    long long t=binarySearch(n,m,0,60000000000);
    if(t==0)
    {
        cout<<n;
        return 0;
    }
    long long rm=n-amuse(m,t-1)-m;
    for(int i=1;i<=m;i++)
    {
        if(t%tArr[i]==0) rm--;
        if(rm==0)
        {
            cout<<i;
            break;
        }
    }
}


// 22 5
// 1 2 3 4 5
// 17 8 -> 8,4,2,2,1
// 7 -> 7,3,2,1,1  14