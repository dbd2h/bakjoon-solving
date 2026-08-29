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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ch=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            ch=1;
            continue;
        }
        if(s[i]==s[i-1]) res++;
        else ch++;
    }
    if(ch/2<=k) res+=ch-1;
    else res+=k*2;
    cout<<res;
}