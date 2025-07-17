#include <iostream>
#include <string>

int main()
{  
    std::string s;
    std::cin>>s;
    bool isLazer=true;
    int lcount=0;
    int total=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            isLazer=true;
            lcount++;
        }
        else if(s[i]==')')
        {
            lcount-=1;
            if(isLazer)
            {
                total+=lcount;
                isLazer=false;
            }
            else
            {
                total++;
            }
        }
    }
    std::cout<<total<<"\n";
}