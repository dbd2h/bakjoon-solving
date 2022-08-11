#include <iostream>

int main()
{
    long long number;
    std::cin>>number;
    int shellNumber=1;

    number+=4;
    number/=6;
    while(number>0)
    {
        number-=shellNumber;
        shellNumber++;
    }
    std::cout<<shellNumber<<std::endl;
}