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

void program()
{
    int n,c;
    cin>>n>>c;
    int a[100];
    int b[100];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int res1=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]-b[i]<0)
        {
            res1=-1;
            break;
        }
        res1+=(a[i]-b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    int res2=c;
    for(int i=0;i<n;i++)
    {
        if(a[i]-b[i]<0)
        {
            res2=-1;
            break;
        }
        res2+=(a[i]-b[i]);
    }
    if(res1==-1)
    {
        cout<<res2<<"\n";
    }
    else 
    {
        if(res2!=-1) res1=min(res1,res2);
        cout<<res1<<"\n";
    }
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