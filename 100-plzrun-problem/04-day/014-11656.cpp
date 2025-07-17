#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<std::string> strVec;
    std::string s;
    std::cin>>s;
    for(int i=0;i<s.size();i++)
    {
        strVec.push_back(s.substr(i,s.size()-i));
    }
    std::sort(strVec.begin(),strVec.end());
    for(int i=0;i<s.size();i++)
    {
        std::cout<<strVec[i]<<"\n";
    }
    return 0;
}