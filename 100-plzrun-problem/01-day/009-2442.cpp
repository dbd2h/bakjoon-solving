#include <iostream>

int main()
{
    int height;
    std::cin>>height;

    for(int i=0;i<height;i++)
    {
        for(int j=i;j<height-1;j++)
        {
            std::cout<<" ";
        }
        for(int j=0;j<i*2+1;j++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
}