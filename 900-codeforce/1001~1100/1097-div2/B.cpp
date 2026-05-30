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

int cmp(int n1, int n2)
{
    return n1<n2;
}

void program()
{
    int n;
    cin>>n;
    map<int,bool> m;
    int arr[200000];
    int len=0;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(!m[num])
        {
            m[num]=true;
            arr[len]=num;
            len++;
        }
    }
    sort(arr,arr+len,cmp);
    ll mex=0;
    for(int i=0;i<len;i++)
    {
        if(arr[i]!=i) break;
        mex++;
    }
    ll res=arr[len-1];
    res*=(ll)n;
    if(mex==len)
    {
        res+=(mex-1)*(mex-2)/2;
        res+=(ll)(n-mex+1)*(mex);
    }
    else
    {
        res+=(mex)*(mex-1)/2;
        res+=(ll)(n-mex)*mex;
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