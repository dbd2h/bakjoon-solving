#include <iostream>

int main()
{
    int n,x;
    std::cin>>n>>x;

    for(int count=0;count<n;count++)
    {
        int input;
        std::cin>>input;
        if(input<x)
        {
            std::cout<<input<<" ";
        }
    }
    std::cout<<"\n";
    return 0;
}