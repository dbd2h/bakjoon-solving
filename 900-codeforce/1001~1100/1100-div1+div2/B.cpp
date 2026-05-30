#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

void program()
{
    int n;
    cin>>n;
    ll A[100000];
    ll B[100000];
    ll res=0;
    int maxV=0;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
    for(int i=0;i<n;i++)
    {
        if(A[i]>B[i])
        {
            ll c=A[i];
            A[i]=B[i];
            B[i]=c;
        }
        res+=B[i];
        if(A[i]>maxV) maxV=A[i];
    }
    cout<<res+maxV<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}