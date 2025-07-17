#include <iostream>
#include <string>

std::string eightToTwo(int num, bool front)
{
    std::string s;
    for(int i=0;i<3;i++)
    {
        if(num%2==1)
        {
            s='1'+s;
        }
        else
        {
            s='0'+s;
        }
        num/=2;
        if(front&&!num)
        {
            return s;
        }
    }
    return s;
}

int main()
{
    std::string num;
    std::cin>>num;
    for(int i=0;i<num.size();i++)
    {
        if(i==0)
        {
            std::cout<<eightToTwo(num[i]-'0',true);
        }
        else
        {
            std::cout<<eightToTwo(num[i]-'0',false);
        }
    }
}