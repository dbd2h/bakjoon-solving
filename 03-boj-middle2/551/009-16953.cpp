#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int minV=1;
    while(a!=b)
    {
        if(a>b)
        {
            minV=-1;
            break;
        }
        minV++;
        if(b%10==1)
        {
            b=(b-1)/10;
        }
        else if(b%2==0)
        {
            b/=2;
        }
        else
        {
            minV=-1;
            break;
        }
    }
    cout<<minV;
}