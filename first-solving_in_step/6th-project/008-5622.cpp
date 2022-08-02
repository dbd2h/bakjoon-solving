#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin>>str;
    int totalTime=0;
    for(int i=0;i<str.length();i++)
    {
        int dial=str[i]-'A';
        if(dial>=25)
        {
            dial-=2;
        }
        else if(dial>=18)
        {
            dial-=1;
        }
        totalTime+=dial/3+3;
    }
    std::cout<<totalTime<<"\n";
    
}