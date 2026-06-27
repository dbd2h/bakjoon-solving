#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

using namespace std;

bool cmp(int n1, int n2)
{
    return n1>n2;
}

void program()
{
    int n;
    cin>>n;
    int arr[3000];
    int cArr[3000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cArr[i]=arr[i];
    } 
    sort(cArr,cArr+n,cmp);
    ll maxV=cArr[1];
    ll resArr[3000];
    for(int i=0;i<n;i++)
    {
        int idx=i;
        ll res=0;
        int count=1;
        ll cur=0;
        while(true)
        {
            if(arr[idx]>cur) cur=arr[idx];
            if(cur>=maxV) break;
            count++;
            res+=cur;
            idx++;
            idx%=n;
        }
        idx=(i+n-1)%n;
        cur=0;
        while(true)
        {
            if(arr[idx]>cur) cur=arr[idx];
            if(cur>=maxV) break;
            count++;
            res+=cur;
            idx=idx+n-1;
            idx%=n;
        }
        res+=(ll)(n-count)*maxV;
        resArr[i]=res;
    }
    for(int i=0;i<n;i++) cout<<resArr[i]<<" ";
    cout<<"\n";
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