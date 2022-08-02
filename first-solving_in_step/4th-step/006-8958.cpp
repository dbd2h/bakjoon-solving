#include <iostream>

int main()
{
    int repeat;
    std::cin>>repeat;

    for(int count=0;count<repeat ;count++)
    {
        char oxArray[80]={0};
        std::cin>>oxArray;
        int seq=1;
        int totalScore=0;
        for(int i=0;i<sizeof oxArray;i++)
        {
            char ox=oxArray[i];
            if(ox=='O')
            {
                totalScore+=seq;
                seq++;
            }
            else if(ox=='X')
            {
                seq=1;
            }
            else{
                break;
            }
        }
        std::cout<<totalScore<<std::endl;
    }
    return 0;
}