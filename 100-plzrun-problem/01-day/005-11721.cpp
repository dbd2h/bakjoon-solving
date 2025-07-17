#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin>>str;
    int strLength=str.length();
    int startPoint=0;
    while(strLength)
    {
        if(strLength>10)
        {
            std::cout<<str.substr(startPoint,10)<<"\n";
            startPoint+=10;
            strLength-=10;
        }
        else
        {
            std::cout<<str.substr(startPoint,strLength)<<"\n";
            strLength=0;
        }
    }
    return 0;
}