#include <iostream>

int main()
{
    int count;
    std::cin>>count;

    for(int i=1;i<=count;i++)
    {
        int a,b;
        std::cin>>a>>b;
        std::cout<<"Case #"<<i<<": "<<a+b<<"\n";
    }
    return 0;
}