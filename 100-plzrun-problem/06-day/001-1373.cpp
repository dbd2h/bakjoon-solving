#include <iostream>
#include <string>

int twoToTen(std::string s)
{
    int len=s.size();
    if(len==1)
    {
        if(s[0]=='1')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(s[len-1]=='0')
    {
        return 2*twoToTen(s.substr(0,len-1));
    }
    else
    {
        return 1+2*twoToTen(s.substr(0,len-1));
    }
}

int main()
{
    std::string s;
    std::cin>>s;
    int len=s.size();
    int remain=len%3;
    if(remain!=0)
    {
        std::cout<<twoToTen(s.substr(0,remain));
    }
    for(int i=0;i<len/3;i++)
    {
        std::cout<<twoToTen(s.substr(remain+i*3,3));
    }
    std::cout<<"\n";
}