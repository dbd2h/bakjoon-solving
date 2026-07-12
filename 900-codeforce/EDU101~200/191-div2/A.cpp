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
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int res1=n/(a+b);
    if(n%(a+b)!=0) res1++;
    int res2=c;
    n-=a*c;
    if(n>0) res2+=n/(a+b*10);
    if(n%(a+b*10)!=0) res2++;
    cout<<min(res1,res2)<<"\n";
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