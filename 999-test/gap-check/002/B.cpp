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
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    int res1=a+x;
    int res2=b+y;
    if(res1%2==1 && res2%2==1) cout<<"odd";
    else if(res1%2==0 && res2%2==0) cout<<"even";
    else cout<<"mix";
}