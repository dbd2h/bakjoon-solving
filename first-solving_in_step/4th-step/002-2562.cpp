#include <iostream>

int main()
{
    int numArr[9]={};
    int index,max;

    for(int count=0;count<9;count++)
    {
        std::cin>>numArr[count];
        if(count==0)
        {
            index=1;
            max=numArr[count];
        }
        else if(numArr[count]>max)
        {
            max=numArr[count];
            index=count+1;
        }
    }
    std::cout<<max<<"\n"<<index<<"\n";
    return 0;
}