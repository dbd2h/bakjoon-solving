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
    string s;
    cin>>s;
    int len=s.size();
    ll res=0;
    for(int i=0;i<len;i++)
    {
        int l=i;
        int r=i;
        bool isC=false;
        while(l>=0 && r<len)
        {
            if(s[l]==s[r]) res++;
            else if(!isC)
            {
                isC=true;
                res++;
            }
            else break;
            l--;
            r++;
        }
        l=i;
        r=i+1;
        isC=false;
        while(l>=0 && r<len)
        {
            if(s[l]==s[r]) res++;
            else if(!isC)
            {
                isC=true;
                res++;
            }
            else break;
            l--;
            r++;
        }
    }
    cout<<res;
}