#include <iostream>
#include <string>

int main()
{
    int alpha[26]={0};

    std::string str;
    std::cin>>str;

    for(int i=0;i<str.length();i++)
    {
        int unit=str[i]-'A';
        if(unit>26)
        {
            unit=unit-'a'+'A';
        }
        alpha[unit]+=1;
    }

    int max=alpha[0];
    int index=0;
    bool isDup=false;
    for(int i=0;i<sizeof(alpha)/sizeof(int);i++)
    {
        if(alpha[i]>max)
        {
            max=alpha[i];
            index=i;
            isDup=false;
        }
        else if(alpha[i]==max && i!=0)
        {
            isDup=true;
        }
    }
    if(isDup)
    {
        std::cout<<'?'<<"\n";
    }
    else
    {
        std::cout<<char(index+'A')<<"\n";
    }

    return 0;
}
