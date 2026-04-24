#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

ll absF(ll num)
{
    if(num<0) return -num;
    return num;
}

int cmp(ll a, ll b)
{
    return a<b;
}

int main()
{
    int n;
    cin>>n;
    ll arr[5000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n, cmp);
    ll res=1e10;
    ll resArr[3];
    for(int i=1;i<n-1;i++)
    {
        int l=0;
        int r=n-1;
        while(l<i && i<r)
        {
            ll cur=arr[l]+arr[i]+arr[r];
            if(absF(res)>absF(cur))
            {
                res=cur;
                resArr[0]=arr[l];
                resArr[1]=arr[i];
                resArr[2]=arr[r];
            } 
            if(cur>0)
            {
                r--;
                continue;
            }
            if(cur<0)
            {
                l++;
                continue;
            }
            if(cur==0)
            {
                break;
            }
        }
    }
    cout<<resArr[0]<<" "<<resArr[1]<<" "<<resArr[2];
}