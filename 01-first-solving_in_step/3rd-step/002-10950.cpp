#include <iostream>

int main()
{
    int count;
    std::cin>>count;

    for(int i=0;i<count;i++)
    {
        int a,b;
        std::cin>>a>>b;
        std::cout<<a+b<<std::endl;
    }
    return 0;
}