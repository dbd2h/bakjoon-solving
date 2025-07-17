#include <iostream>

int gcd(int num1, int num2)
{
    if(num1%num2==0)
    {
        return num2;
    }
    return gcd(num2,num1%num2);
}

int main()
{
    int num1,num2;
    std::cin>>num1>>num2;
    int yak;
    if(num1>num2)
    {
        yak=gcd(num1,num2);
    }
    else
    {
        yak=gcd(num2,num1);
    }
    long long bae=num1*num2/yak;
    std::cout<<yak<<"\n";
    std::cout<<bae<<"\n";
}