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

int main()
{
    int n;
    cin>>n;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        if(s=="take") continue;
        res+=(b-a);
    }
    cout<<res;
}