#include <iostream>

int fibo(int num)
{
    if(num==0)
    {
        return 0;
    }
    else if(num==1)
    {
        return 1;
    }
    return fibo(num-1)+fibo(num-2);
}

int main()
{
    int inputNum;
    std::cin>>inputNum;

    std::cout<<fibo(inputNum)<<std::endl;
}