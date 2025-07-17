#include <iostream>
#include <string>

int main()
{
    while (true)
    {
        std::string s;
        std::getline(std::cin,s);
        int small,big,num,blank;
        small=0;
        big=0;
        num=0;
        blank=0;
        if(std::cin.eof()==true)
        {
            break;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                blank++;
            }
            else if(s[i]-'0'>=0 && s[i]-'0'<=9)
            {
                num++;
            }
            else if(s[i]-'A'>=0 && s[i]-'A'<=26)
            {
                big++;
            }
            else
            {
                small++;
            }
            
        }
        std::cout<<small<<" "<<big<<" "<<num<<" "<<blank<<"\n";
    }
    return 0;
}