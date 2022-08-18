#include <iostream>

int main()
{
    int total;
    std::cin>>total;

    for(int count=1;count<=total;count++)
    {
        int a,b;
        std::cin>>a>>b;
        std::cout<<"Case #"<<count<<": "<<a<<" + "<<b<<" = "<<a+b<<"\n";
    }
    return 0;
}