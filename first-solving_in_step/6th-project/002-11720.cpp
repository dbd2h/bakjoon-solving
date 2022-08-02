#include <iostream>
#include <string>

int main()
{
    int len;
    std::string str;

    std::cin>>len>>str;
    int total=0;
    for(int count=0;count<len;count++)
    {
        int unit=str[count]-'0';
        total+=  unit;
    }
    std::cout<<total<<"\n";
    return 0;
}