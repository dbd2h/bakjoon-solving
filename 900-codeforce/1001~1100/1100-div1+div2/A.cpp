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
    int arr[1000];
    for(int i=0;i<n;i++) cin>>arr[i];
    int res=1e9;
    for(int i=1;i<=1000;i++)
    {
        int maxV=0;
        for(int j=0;j<n;j++)
        {
            int sub=abs(arr[j]-i);
            if(sub>maxV) maxV=sub;
        }
        if(res>maxV) res=maxV;
    }
    cout<<res<<"\n";
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