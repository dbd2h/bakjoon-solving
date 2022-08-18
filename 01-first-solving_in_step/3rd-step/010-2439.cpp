#include <iostream>

int main()
{
    int height;
    std::cin>>height;

    for(int count=1;count<=height;count++)
    {
        for(int blank=1;blank<=height-count;blank++)
        {
            std::cout<<" ";
        }
        for(int star=1;star<=count;star++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    return 0;
}