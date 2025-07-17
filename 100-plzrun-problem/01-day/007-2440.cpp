#include <iostream>

int main()
{
    int height;
    std::cin>>height;

    for(int i=0;i<height;i++)
    {
        for(int j=i;j<height;j++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
}