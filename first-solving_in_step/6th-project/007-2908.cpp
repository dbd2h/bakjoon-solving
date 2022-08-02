#include <iostream>

int main()
{
    int a,b;
    std::cin>>a>>b;
    int revA=0,revB=0;
    int hundred=100;
    for(int i=0;i<3;i++)
    {
        revA+=(a%10*hundred);
        revB+=(b%10*hundred);
        a/=10;
        b/=10;
        hundred/=10;
    }
    int bigger;
    if(revA>revB)
    {
        bigger=revA;   
    }
    else
    {
        bigger=revB;
    }
    std::cout<<bigger<<"\n";
    return 0;
}