#include <iostream>

int min(int l,int r)
{
    if(l<r)
    {
        return l;
    }
    else
    {
        return r;
    }
}

int main()
{
    int height;
    std::cin>>height;

    for(int i=0;i<height*2-1;i++)
    {
        for(int j=0;j<height-min(i+1,height*2-i-1);j++)
        {
            std::cout<<" ";
        }
        for(int j=0;j<min(i+1,height*2-i-1);j++)
        {
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
}