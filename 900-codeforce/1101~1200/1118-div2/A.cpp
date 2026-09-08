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

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

void program()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++) cin>>arr[i];
    int num1=arr[0];
    int num2=arr[n-1];
    cout<<gcd(num1,num2)<<"\n";
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