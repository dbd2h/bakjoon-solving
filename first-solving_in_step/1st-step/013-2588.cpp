#include<iostream>

int main()
{
    int num1,num2;
    std::cin>>num1>>num2;
    std::cout<<num1*(num2%100%10)<<std::endl;
    std::cout<<num1*(num2%100/10)<<std::endl;
    std::cout<<num1*(num2/100)<<std::endl;
    std::cout<<num1*num2<<std::endl;
    return 0;
}