#include <iostream>

using namespace std;

long long absNum(long long a)
{
    return a>0 ? a : -a;
}

long long gcd(long long a, long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

long long shoelace(long long ax, long long ay, long long bx, long long by, long long cx, long long cy)
{
    long long result=ax*by+bx*cy+cx*ay-(ay*bx+by*cx+cy*ax);
    return absNum(result);
}

int main()
{
    long long ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    long long gcdAB, gcdBC, gcdCA;
    gcdAB=gcd(absNum(bx-ax),absNum(by-ay));
    gcdBC=gcd(absNum(cx-bx),absNum(cy-by));
    gcdCA=gcd(absNum(ax-cx),absNum(ay-cy));
    if(gcdAB==1 || gcdBC==1 || gcdCA==1)
    {
        cout<<-1;
        return 0;
    }
    long long maxResult=0;
    long long minResult=-1;
    for(int i=-1;i<=1;i+=2)
    {
        for(int j=-1;j<=1;j+=2)
        {
            for(int k=-1;k<=1;k+=2)
            {
                long long size=shoelace(ax+(bx-ax)/gcdAB*((gcdAB+i)%gcdAB),ay+(by-ay)/gcdAB*((gcdAB+i)%gcdAB), bx+(cx-bx)/gcdBC*((gcdBC+j)%gcdBC), by+(cy-by)/gcdBC*((gcdBC+j)%gcdBC), cx+(ax-cx)/gcdCA*((gcdCA+k)%gcdCA), cy+(ay-cy)/gcdCA*((gcdCA+k)%gcdCA));
                if(maxResult<size) maxResult=size;
                if(minResult==-1 || minResult>size) minResult=size;
            }
        }
    }
    cout<<maxResult<<" "<<minResult;

}