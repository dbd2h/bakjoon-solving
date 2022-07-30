#include <iostream>

int main()
{
    int count;
    long long result=0;
    std::cin>>count;

    for(int i=1;i<=count;i++)
    {
        result+=i;
    }
    std::cout<<result<<std::endl;
    return 0;
}