#include <iostream>
#include <string>

int main(){
   std::string str;
   std::getline(std::cin,str);
   int wordNum=1;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ' && str[i-1]!=' ')
        {
            wordNum++;
        }
    }
    if(str[str.length()-1]==' ')
    {
        wordNum--;
    }
    if(str[0]==' ')
    {
        wordNum--;
    }
    std::cout<<wordNum<<"\n";
}