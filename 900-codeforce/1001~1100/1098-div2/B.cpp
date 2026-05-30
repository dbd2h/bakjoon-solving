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
    int n,x1,x2,k;
    cin>>n>>x1>>x2>>k;
    int res=min((x1-x2+n)%n,(x2-x1+n)%n)+k;
    if(n<=3) res=1;
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