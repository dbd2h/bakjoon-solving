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
#define LEN 200001

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int odd=0;
    int c=0;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='0')
        {
            c++;
        }
        if(c%2==1)
        {
            res+=odd;
            odd++;
        }
        else
        {
            res+=(i-odd);
        }
    }
    cout<<res;
}