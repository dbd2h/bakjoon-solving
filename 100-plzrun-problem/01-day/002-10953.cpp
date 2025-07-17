#include <iostream>
#include <string>

int main()
{
    int count;
    std::cin>>count;
    for(int i=0;i<count;i++)
    {
        std::string str;
        std::cin>>str;
        int result=str[0]+str[2]-'0'*2;
        std::cout<<result<<"\n";
    }
}