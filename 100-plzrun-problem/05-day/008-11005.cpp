#include <iostream>
#include <string>

int main()
{
    int n, b;
    std::string s;
    std::cin>>n>>b;
    int len=0;
    while(n!=0)
    {
        int remain=n%b;
        n/=b;
        if(remain>=10)
        {
            s+=char(remain+55);
        }
        else
        {   
            s+=char(remain+48);
        }
        len++;
    }
    for(int i=len-1;i>=0;i--)
    {
        std::cout<<s[i];
    }
    std::cout<<"\n";
}