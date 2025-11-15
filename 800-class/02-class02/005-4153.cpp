#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    while(!(a==0 && b==0 && c==0))
    {
        if(a>c)
        {
            ll change=a;
            a=c;
            c=change;
        }
        if(b>c)
        {
            ll change=b;
            b=c;
            c=change;
        }
        if(c*c==(a*a+b*b))
        {
            cout<<"right\n";
        }
        else
        {
            cout<<"wrong\n";
        }
        cin>>a>>b>>c;
    }
}