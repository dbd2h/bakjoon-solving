#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin>>s;
    int alphaArr[26]={0};

    for(int i=0;i<s.size();i++)
    {
        alphaArr[s[i]-'a']+=1;
    }
    for(int i=0;i<26;i++)
    {
        std::cout<<alphaArr[i];
        if(i!=25)
        {
            std::cout<<" ";
        }
    }
    return 0;
}