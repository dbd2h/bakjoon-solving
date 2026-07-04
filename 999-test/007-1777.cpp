#include <iostream>
#include <algorithm>
#include <vector>
#define LEN 100001

using namespace std;

int BIT[LEN]={0};
bool check[LEN]={0};
int arr[LEN];

void update(int x, int n, int num)
{
    while(x<=n)
    {
        BIT[x]+=num;
        x+=x&-x;
    }
    return;
}

int query(int x, int n)
{
    int res=0;
    while(x)
    {
        res+=BIT[x];
        x-=x&-x;
    }
    return res;
}

int bs(int l, int r, int n, int num)
{
    int mid=(l+r)/2;
    int res=n-mid-(query(n,n)-query(mid,n));
    if(res>num) return bs(mid+1,r,n,num);
    else if(res<num || check[mid]) return bs(l,mid-1,n,num);
    else return mid;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int res[LEN];
    for(int i=n;i>=1;i--)
    {
        int idx=bs(1,n,n,arr[i]);
        check[idx]=1;
        update(idx,n,1);
        res[idx]=i;
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}
