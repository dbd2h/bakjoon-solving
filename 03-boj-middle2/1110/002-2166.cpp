#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int coo[10000][2]={0};
    for(int i=0;i<n;i++)
    {
        cin>>coo[i][0]>>coo[i][1];
    }
    long double result=0;
    long double x=coo[0][0];
    long double y=coo[0][1];
    for(int i=1;i<n-1;i++)
    {
        long double x1=coo[i][0]-x;
        long double y1=coo[i][1]-y;
        long double x2=coo[i+1][0]-x;
        long double y2=coo[i+1][1]-y;
        long double sizeV=((x2*y1)-(x1*y2))/2;
        result+=sizeV;
    }
    if(result<0) result=-result;
    cout<<fixed;
    cout.precision(1);
    cout<<result;
}