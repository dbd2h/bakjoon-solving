#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s;
    long long num;
    std::cin>>num;
    if(num==0)
    {
        s='0';
    }
    while(num!=0)
    {
        if(num%-2==0)
        {
            num/=-2;
            s+='0';
        }
        else
        {
            num=(num-1)/-2;
            s+='1';
        }
    }
    std::reverse(s.begin(),s.end());
    std::cout<<s<<"\n";
}
