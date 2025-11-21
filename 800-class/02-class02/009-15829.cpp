#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    int l;
    cin>>l;
    string s;
    cin>>s;
    ll M=1234567891;
    ll res=0;
    ll r=1;
    for(int i=0;i<l;i++)
    {
        ll cur=s[i]-'a'+1;
        res+=r*cur;
        res%=M;
        r*=31;
        r%=M;
    }
    cout<<res;
}