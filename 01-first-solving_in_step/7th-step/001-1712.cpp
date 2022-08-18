#include <iostream>

int main()
{
    long long a,b,c;
    std::cin>>a>>b>>c;
    
    int first;
    if(c-b<=0)
    {
        first=-1;
    }
    else
    {
        first=a/(c-b)+1;
    }
    std::cout<<first<<std::endl;
}