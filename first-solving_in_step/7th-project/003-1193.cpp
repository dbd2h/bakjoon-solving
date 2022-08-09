#include <iostream>

int main()
{
    int number;
    int boonmo,boonja;
    std::cin>>number;
    int numberCopy=number;
    int step=1;
    
    for(int i=1;numberCopy>i;i++)
    {
        step++;
        numberCopy-=i;
    }
    step++;
    if(step%2==1)
    {
        boonja=numberCopy;
        boonmo=step-numberCopy;
    }
    else
    {
        boonmo=numberCopy;
        boonja=step-numberCopy;
    }
    std::cout<<boonja<<"/"<<boonmo<<std::endl;
}