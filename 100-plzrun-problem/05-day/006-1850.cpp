#include <iostream>

long long gcd(long long num1, long long num2)
{
    if(num1%num2==0)
    {
        return num2;
    }
    return gcd(num2,num1%num2);
}

int main()
{
    long long num1,num2,yak;
    std::cin>>num1>>num2;
    if(num1>num2)
    {
        yak=gcd(num1,num2);
    }
    else
    {
        yak=gcd(num2,num1);
    }
    for(int i=0;i<yak;i++)
    {
        std::cout<<1;
    }
    std::cout<<"\n";
}