#include <iostream>
#include <string>

int main()
{
    int a, b, c, result;
    int unitsArray[10]={0};
    std::cin>>a>>b>>c;
    result=a*b*c;
    std::string resultToStr=std::to_string(result);
    for(int units=0;units<resultToStr.length();units++)
    {
        unitsArray[result%10]++;
        result/=10;
    }
    for(int count=0;count<10;count++)
    {
        std::cout<<unitsArray[count]<<"\n";
    }
    return 0;
}