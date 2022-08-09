#include <iostream>

int main()
{
    int totalValue, count;
    std::cin>>totalValue>>count;
    int total=0;

    for(int i=0;i<count;i++)
    {
        int value,c;
        std::cin>>value>>c;

        total+=value*c;
    }
    if(totalValue==total)
    {
        std::cout<<"Yes"<<std::endl;
    }
    else
    {
        std::cout<<"No"<<std::endl;
    }
}