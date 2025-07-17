#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::getline(std::cin, s);
    std::string result;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]-'A'>=0 && s[i]-'Z'<=0)
        {
            if(s[i]-'N'>=0)
            {
                result+=(char)(s[i]-13);
            }
            else
            {
                result+=(char)(s[i]+13);
            }
        }
        else if(s[i]-'a'>=0 && s[i]-'z'<=0)
        {
            if(s[i]-'n'>=0)
            {
                result+=(char)(s[i]-13);
            }
            else
            {
                result+=(char)(s[i]+13);
            }
        }
        else
        {
            result+=s[i];
        }
    }
    std::cout<<result<<"\n";
}