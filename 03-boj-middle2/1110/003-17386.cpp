#include <iostream>

using namespace std;

int main()
{
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    long long v1x=x2-x1;
    long long v1y=y2-y1;
    long long v2x=x3-x1;
    long long v2y=y3-y1;
    long long v3x=x4-x1;
    long long v3y=y4-y1;
    long long v4x=x4-x2;
    long long v4y=y4-y2;
    long long v5x=x4-x3;
    long long v5y=y4-y3;
    long long outpro1=(v1x*v2y-v2x*v1y);
    long long outpro2=(v1x*v3y-v3x*v1y);
    long long outpro3=(v5x*v3y-v5y*v3x);
    long long outpro4=(v5x*v4y-v5y*v4x);
    if(outpro1>0 && outpro2>0 || outpro1<0 && outpro2<0) cout<<0;
    else if(outpro3>0 && outpro4>0 || outpro3<0 && outpro4<0) cout<<0;
    else cout<<1;
}