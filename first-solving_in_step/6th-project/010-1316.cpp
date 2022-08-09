#include <iostream>

bool isGroupWord(char *str, int len)
{
    int alpha[26]={0};
    char currentWord=str[0];
    int smallA='a';
    for(int i=0;i<len;i++)
    {
        int index=str[i]-smallA;
        if(!str[i])
        {
            break;
        }
        if(alpha[index]==0)
        {
            alpha[index]=1;
            currentWord=str[i];
        }
        else if(alpha[index]==1&&currentWord!=str[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int count;
    std::cin>>count;
    int groupWord=0;
    for(int wordCount=0;wordCount<count;wordCount++)
    {
        char word[102]="";
        std::cin>>word;
        if(isGroupWord(word, sizeof(word)))
        {
            groupWord++;
        }
    }
    std::cout<<groupWord<<std::endl;
    return 0;
}