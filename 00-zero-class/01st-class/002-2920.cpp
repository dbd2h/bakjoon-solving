#include <iostream>

int main()
{
    bool isAscending=true;
    bool isDescending=true;
    int before=0;
    for(int i=0;i<8;i++)
    {
        int inputNum;
        std::cin>>inputNum;
        if(before==0)
        {
            before=inputNum;
        }
        else if(before<inputNum)
        {
            isDescending=false;
        }
        else
        {
            isAscending=false;
        }
        before=inputNum;
    }
    if(isAscending)
    {
        std::cout<<"ascending"<<"\n";
    }
    else if(isDescending)
    {
        std::cout<<"descending"<<"\n";
    }
    else
    {
        std::cout<<"mixed"<<"\n";
    }
}