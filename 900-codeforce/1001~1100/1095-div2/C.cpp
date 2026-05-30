#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 200001

using namespace std;

int binarySearch(int l, int r, int arr[], int n)
{
    if(l>r) return l-1;
    int mid=(l+r)/2;
    bool check[LEN];
    bool bit[LEN];
    for(int i=0;i<=n;i++)
    {
        check[i]=0;
        bit[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int cur=arr[i];
        if(cur>mid || bit[cur]) continue;
        bit[cur]=1;
        check[i]=1;
    }
    int idx=n-1;
    while(idx>=0)
    {
        if(check[idx]==0) break;
        idx--;
    }
    bool isT=true;
    for(int i=mid;i>=0;i--)
    {
        if(bit[i]) continue;
        if(idx<0)
        {
            isT=false;
            break;
        }
        int cur=(arr[idx]-1)/2;
        if(i>cur)
        {
            isT=false;
            break;
        }
        check[idx]=1;
        while(idx>=0)
        {
            if(check[idx]==0) break;
            idx--;
        }
    }
    if(isT) return binarySearch(mid+1,r,arr,n);
    else return binarySearch(l,mid-1,arr,n);
}

void program()
{
    int n;
    cin>>n;
    int arr[LEN];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int res=binarySearch(0,n-1,arr,n);
    cout<<res+1<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}