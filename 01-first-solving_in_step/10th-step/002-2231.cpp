#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int createdResult=0;
    for(int i=1;i<inputNum;i++)
    {
        int copyI=i;
        int createdNum=i;
        while(copyI>0)
        {
            createdNum+=(copyI%10);
            copyI/=10;
        }
        if(inputNum==createdNum)
        {
            createdResult=i;
            break;
        }
    }
    std::cout<<createdResult<<std::endl;
}