#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 1000001
#define MOD (ll)998244353

using namespace std;

int arr[LEN];
bool check[LEN];

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>arr[i];
        check[i]=0;
    } 
    bool isInc=true;
    arr[0]=0;
    for(int i=1;i<=n-1;i++)
    {
        if(arr[i]==n)
        {
            cout<<0<<"\n";
            return;
        }
        if(arr[i-1]==arr[i]) continue;
        if(check[arr[i]])
        {
            cout<<0<<"\n";
            return;
        }
        check[arr[i]]=1;
        if(isInc && arr[i-1]<arr[i])
        {
            if(arr[i]==n-1) isInc=false;
            continue;
        }
        if(!isInc && arr[i-1]>arr[i]) continue;
        cout<<0<<"\n";
        return;
    }
    sort(arr+1,arr+n);
    ll res=2;
    int c=0;
    int minus=0;
    for(int i=1;i<=n-1;i++)
    {
        if(i==1) continue;
        if(arr[i]<i)
        {
            cout<<0<<"\n";
            return;
        }
        if(arr[i-1]==arr[i])
        {
            c++;
            continue;
        }
        minus++;
        while(c)
        {
            res*=(arr[i-1]-minus);
            res%=MOD;
            minus++;
            c--;
        }
    }
    while(c)
    {
        res*=(n-2-minus);
        res%=MOD;
        minus++;
        c--;
    }
    cout<<res<<"\n";
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