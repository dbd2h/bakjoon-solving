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
    int count;
    std::cin>>count;
    for(int i=0;i<count;i++)
    {
        int num1,num2,yak;
        long long bae;
        std::cin>>num1>>num2;
        if(num1>num2)
        {
            yak=gcd(num1,num2);
        }
        else
        {
            yak=gcd(num2,num1);
        }
        bae=num1*num2/yak;
        std::cout<<bae<<"\n";
    }
}