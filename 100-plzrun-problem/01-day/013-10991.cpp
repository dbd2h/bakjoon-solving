#include <iostream>

void altering(int count)
{
    int num=count-1;
    std::cout<<"*";
    while(num)
    {
        std::cout<<" *";
        num--;
    }
    return;
}

int main()
{
    int height;
    std::cin>>height;
    for(int i=1;i<=height;i++)
    {
        for(int j=i;j<height;j++)
        {
            std::cout<<" ";
        }
        altering(i);
        std::cout<<"\n";
    }
    return 0;
}