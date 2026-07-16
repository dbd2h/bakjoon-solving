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

int main()
{
    int n;
    cin>>n;
    lld p;
    cin>>p;
    p=1-p;
    lld res=1;
    while(n)
    {
        if(n%2==1) res=res*p+(1-res)*(1-p);
        p=p*p+(1-p)*(1-p);
        n/=2;
    }
    cout.precision(9);
    cout<<fixed;
    cout<<res;
}