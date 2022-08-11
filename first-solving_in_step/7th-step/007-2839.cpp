#include <iostream>

int main()
{
    int kg;
    bool isMinus=false;
    std::cin>>kg;
    int threeCount=0;

    while((kg-3*threeCount)%5!=0)
    {
        if(kg-3*threeCount<0)
        {
            isMinus=true;
            break;
        }
        threeCount++;
    }
    if(isMinus)
    {
        std::cout<<-1<<std::endl;
    }
    else
    {
        std::cout<<(kg-3*threeCount)/5+threeCount<<std::endl;
    }
    return 0;
}