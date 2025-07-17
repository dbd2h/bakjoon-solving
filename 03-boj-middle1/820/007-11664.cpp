#include <iostream>
#include <cmath>

using namespace std;

long double pita(long double a[], long double b[])
{
    long double x,y,z;
    x=a[0]-b[0];
    y=a[1]-b[1];
    z=a[2]-b[2];
    return sqrt(x*x+y*y+z*z);
}

long double binarySearch(long double a[], long double b[], long double c[])
{
    long double middle[3];
    for(int i=0;i<3;i++)
    {
        middle[i]=(a[i]+b[i])/2;
    }
    long double atoc=pita(a,c);
    long double btoc=pita(b,c);
    if(pita(a,middle)<0.0000000001) return pita(middle,c);
    else if(atoc>btoc) return binarySearch(middle,b,c);
    else return binarySearch(a,middle,c);
}

int main()
{
    long double a[3]={0};
    long double b[3]={0};
    long double c[3]={0};

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==0) cin>>a[j];
            else if(i==1) cin>>b[j];
            else if(i==2) cin>>c[j];
        }
    }
    cout.precision(10);
    cout<<binarySearch(a,b,c);
}