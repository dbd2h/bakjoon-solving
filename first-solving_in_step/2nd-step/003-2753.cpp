#include<iostream>

int main()
{
    int year;
    int leapYearTrue=0;
    std::cin>>year;
    if((year%4==0 && year%100!=0)||year%400==0)
    {
        leapYearTrue=1;
    }
    std::cout<<leapYearTrue<<std::endl;
    return 0;
}