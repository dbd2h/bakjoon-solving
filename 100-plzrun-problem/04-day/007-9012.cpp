#include <iostream>
#include <string>

int main()
{
    int inputNum;
    std::cin>>inputNum;

    for(int i=0;i<inputNum;i++)
    {
        std::string s;
        std::cin>>s;
        int strSize=s.size();
        int lpar=0;
        for(int j=0;j<strSize;j++)
        {
            if(s[j]=='(')
            {
                lpar++;
            }
            else if(s[j]==')')
            {
                lpar--;
                if(lpar<0)
                {
                    break;
                }
            }
        }
        if(lpar!=0)
        {
            std::cout<<"NO"<<"\n";
        }
        else
        {
            std::cout<<"YES"<<"\n";
        }
    }
    return 0;
}