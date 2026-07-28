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

using namespace std;

int P[10];
int Q[10];
bool bit[10]={0};
int arr[10];
ll res=0;

void per(int n, int c)
{
    if(n==c)
    {
        for(int i=0;i<=n;i++)
        {
            if(i==n) return;
            if(arr[i]>P[i]) break;
            else if(arr[i]<P[i]) return;
        }
        for(int i=0;i<=n;i++)
        {
            if(i==n) return;
            if(arr[i]<Q[i]) break;
            else if(arr[i]>Q[i]) return;
        }
        res++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(bit[i]==1) continue;
        arr[c]=i;
        bit[i]=1;
        per(n,c+1);
        bit[i]=0;
    }
}

int main()
{
    int n;
    cin>>n;
    res=0;
    for(int i=0;i<n;i++) cin>>P[i];
    for(int i=0;i<n;i++) cin>>Q[i];
    per(n,0);
    cout<<res;

}   