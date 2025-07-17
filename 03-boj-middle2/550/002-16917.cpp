#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int price=0;
    if(a+b>c*2)
    {
        price+=c*2*min(x,y);
        if(x>y)
        {
            x-=y;
            y=0;
            if(a>c*2) price+=c*2*x;
            else price+=a*x;
        }
        else if(y>x)
        {
            y-=x;
            x=0;
            if(b>c*2) price+=c*2*y;
            else price+=b*y;
        }
    }
    else price+=(a*x+b*y);
    cout<<price;
}