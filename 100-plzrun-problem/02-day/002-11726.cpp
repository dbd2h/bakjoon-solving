#include <iostream>

long long rectangle(int width)
{
    if(width==1)
    {
        return 1;
    }
    else if(width==2)
    {
        return 2;
    }
    long long num1,num2,num3;
    num1=1;
    num2=2;
    num3;
    for(int i=2;i<width;i++)
    {
        num3=(num1+num2)%10007;
        num1=num2;
        num2=num3;
    }
    return num3;
}

int main()
{
    int width;
    std::cin>>width;

    std::cout<<rectangle(width)<<"\n";
    return 0;
}