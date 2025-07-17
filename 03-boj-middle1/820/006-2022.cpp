#include <iostream>
#include <cmath>

using namespace std;

int n=0;

long double pita(long double a, long double c)
{  
    long double diva=a/3;
    long double divc=c/3;
    long double result=divc*divc-diva*diva;
    if(result<0) return -1;
    return sqrt(result)*3;
}

long double binarySearch(long double l, long double r, long double x, long double y, long double c)
{
    n++;
    long double middle=(l+r)/2;
    long double verx=pita(middle,x);
    long double very=pita(middle,y);
    
    if(verx==-1 || very==-1)
    {
        return binarySearch(l,middle,x,y,c);
    }
    long double c2=verx/(verx+very)*very;
    long double c3=very/(verx+very)*verx;
    if(c2+0.0000000001>c && c2-0.0000000001<c) return middle;
    else if(c2<c) return binarySearch(l,middle,x,y,c);
    else return binarySearch(middle,r,x,y,c);
}

int main()
{
    long double x,y,c;
    cin>>x>>y>>c;
    cout<<binarySearch(0,3000000000,x,y,c);
}