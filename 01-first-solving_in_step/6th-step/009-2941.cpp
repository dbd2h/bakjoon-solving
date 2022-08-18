#include <iostream>

int main()
{
    char str[101]="";
    int croatiaWord=0;
    std::cin>>str;

    for(int i=0;i<sizeof(str);i++)
    {
        if(!str[i])
        {
            break;
        }
        if(str[i+1]=='-')
        {
            if(str[i]=='c'||str[i]=='d')
            {
                i++;
            }
        }
        else if(str[i]=='c')
        {
            if(str[i+1]=='=')
            {
                i++;
            }
        }
        else if(str[i]=='d')
        {
            if(str[i+1]=='z'&&str[i+2]=='=')
            {
                i+=2;
            }
        }
        else if(str[i+1]=='=')
        {
            if(str[i]=='z'||str[i]=='s')
            {
                i++;
            }
        }
        else if(str[i+1]=='j')
        {
            if(str[i]=='l'||str[i]=='n')
            {
                i++;
            }
        }
        croatiaWord++;
    }
    std::cout<<croatiaWord<<std::endl;
}