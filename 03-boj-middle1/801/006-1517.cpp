#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000]={0};

void divideAndConquer(int l, int m, int r, long long *result)
{
     
    if(l>=m)
    {
        return;
    }
    divideAndConquer(l, (l+m)/2, m, result);
    divideAndConquer(m, (m+r)/2, r, result);
    int index=l;
    for(int i=m;i<r;i++)
    {
        while(arr[index]<=arr[i] && index!=m)
        {
            index++;
        }
        *result += m-index;
    }
    sort(arr+l,arr+r);
    return;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long result=0;
    divideAndConquer(0,(n)/2,n,&result);
    cout<<result;
}

// 10 9 8 7 6 5 4 3 2 1
// 9 10 7 8 5 6 3 4 1 2
// 