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
    lld res=0;
    lld arr[100000][2];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    for(int i=n-1;i>=0;i--)
    {
        lld num=res*((lld)100-arr[i][1])/(lld)100+arr[i][0];
        if(num>res) res=num;
    }
    cout<<fixed;
    cout.precision(10);
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