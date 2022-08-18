#include <iostream>

int main()
{
    int num1,num2,num3;
    int price=0;
    std::cin>>num1>>num2>>num3;

    if(num1>num2)
    {
        if(num1>num3&&num2!=num3)
        {
            price=num1*100;
        }
        else if(num1<num3)
        {
            price=num3*100;
        }
        else
        {
            price=1000+num3*100;
        }
    }
    else if(num1<num2)
    {
        if(num2>num3&&num1!=num3)
        {
            price=num2*100;
        }
        else if(num2<num3)
        {
            price=num3*100;
        }
        else 
        {
            price=1000+num3*100;
        }
    }
    else
    {
        if(num1==num3)
        {
            price=10000+num1*1000;
        }
        else
        {
            price=1000+num1*100;
        }
    }
    std::cout<<price<<std::endl;
    return 0;
}