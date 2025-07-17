#include <iostream>
#include <string>

int main()
{
    std::string str;
    while (1&&!std::cin.eof())
    {
        getline(std::cin,str);
        std::cout<<str<<"\n";
    }
    return 0;
}