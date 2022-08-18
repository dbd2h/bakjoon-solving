#include <iostream>

int factorial(int num)
{
    if(num==1||num==0)
    {
        return 1;
    }
    return num*factorial(num-1);
}

int main()
{
    int inputNum;
    std::cin>>inputNum;
    std::cout<<factorial(inputNum)<<std::endl;
}