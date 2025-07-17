#include <iostream>
#include <string>

int main()
{
    std::string a,b,c,d;
    std::cin>>a>>b>>c>>d;
    std::cout<<stoll(a+b)+stoll(c+d)<<"\n";
    return 0;
}