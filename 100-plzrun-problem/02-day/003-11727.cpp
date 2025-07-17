#include <iostream>

int rectangle(int width)
{
    if(width==1)
    {
        return 1;
    }
    else if(width==2)
    {
        return 3;
    }
    int num1,num2,num3;
    num1=1;
    num2=3;
    for(int i=2;i<width;i++)
    {
        num3=(num1*2+num2)%10007;
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