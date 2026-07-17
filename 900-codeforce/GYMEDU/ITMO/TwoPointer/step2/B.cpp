#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 100001

using namespace std;

int main()
{
    int n;
    ll s;
    cin>>n>>s;
    ll arr[LEN];
    for(int i=0;i<n;i++) cin>>arr[i];
    int l=-1;
    int r=-1;
    ll sumV=0;
    int res=-1;
    while(r<n)
    {
        if(sumV<s)
        {
            r++;
            if(r==n) break;
            sumV+=arr[r];
        } 
        else
        {
            int len=r-l;
            if(res==-1 || res>len) res=len;
            l++;
            sumV-=arr[l];
        }
    }
    cout<<res;
}