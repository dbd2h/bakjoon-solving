#include <iostream>

void middlePoint(int count)
{
    std::cout<<"*";
    for(int blank=0;blank<count*2-3;blank++)
    {
        std::cout<<" ";
    }
    std::cout<<"*";
}

int main()
{
    int height;
    std::cin>>height;
    for(int i=1;i<=height;i++)
    {
        for(int j=0;j<height-i;j++)
        {
            std::cout<<" ";
        }
        if(i==1)
        {
            std::cout<<"*";
        }
        else if(i==height)
        {
            for(int j=0;j<height*2-1;j++)
            {
                std::cout<<"*";
            }
        }
        else
        {
            middlePoint(i);
        }
        std::cout<<"\n";
    }
}