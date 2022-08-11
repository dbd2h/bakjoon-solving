#include <iostream>
#include <string>

int sumReturn(std::string charA, std::string charB, int i)
{
    int sum;
    if(charA.length()<i+1)
    {
        sum=int(charB[charB.length()-i-1])-48;
    }
    else if(charB.length()<i+1)
    {
        sum=int(charA[charA.length()-i-1])-48;
    }
    else
    {
        sum=int(charA[charA.length()-i-1])+int(charB[charB.length()-i-1])-96;
    }
    return sum;
}

int main()
{
    std::string charA,charB;
    std::cin>>charA>>charB;
    int sum[10001]={0};
    bool isOver=false;
    int count=charA.length()>charB.length()?charA.length():charB.length();
    bool lastIsOver=false;

    for(int i=0;i<count;i++)
    {
        int unit;
        if(isOver)
        {
            unit=sumReturn(charA,charB,i)+1;
            if(unit>=10)
            {
                sum[count-i-1]=unit-10;
                isOver=true;
            }
            else
            {
                sum[count-i-1]=unit;
                isOver=false;
            }
        }
        else
        {
            unit=sumReturn(charA,charB,i);
            if(unit>=10)
            {
                sum[count-i-1]=unit-10;
                isOver=true;
            }
            else
            {
                sum[count-i-1]=unit;
                isOver=false;
            }
        }
    }
    if(isOver)
    {
        std::cout<<1;
    }
    for(int i=0;i<count;i++)
    {
        std::cout<<sum[i];
    }
}