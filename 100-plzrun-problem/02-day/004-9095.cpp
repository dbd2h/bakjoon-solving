#include <iostream>

int caseNum(int num)
{
    if(num<0)
    {
        return 0;
    }
    else if(num==0)
    {
        return 1;
    }
    else
    {
        return caseNum(num-1)+caseNum(num-2)+caseNum(num-3);
    }
}

int main()
{
    int t;
    std::cin>>t;

    for(int i=0;i<t;i++)
    {
        int num;
        std::cin>>num;
        std::cout<<caseNum(num)<<"\n";
    }
    return 0;
}