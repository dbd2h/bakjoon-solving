#include <iostream>

int main()
{
    int number;
    std::cin>>number;

    for(int i=1;i<=9;i++)
    {
        std::cout<<number<<" * "<<i<<" = "<<number*i<<std::endl;
    }
    return 0;
}