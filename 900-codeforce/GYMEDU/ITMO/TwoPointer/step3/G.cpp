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
    ll c;
    cin>>n>>c;
    string s;
    cin>>s;
    int l=-1;
    int r=-1;
    int a=0;
    int b=0;
    ll sumV=0;
    ll res=0;
    while(r<n)
    {
        if(sumV<=c)
        {
            res=max(res,(ll)r-l);
            r++;
            if(r>=n) break;
            if(s[r]=='a')
            {
                a++;
            }
            else if(s[r]=='b')
            {
                b++;
                sumV+=a;
            }
        }
        else
        {
            l++;
            if(s[l]=='a')
            {
                sumV-=b;
                a--;
            }
            else if(s[l]=='b')
            {
                b--;
            }
        }
    }
    cout<<res;
}
