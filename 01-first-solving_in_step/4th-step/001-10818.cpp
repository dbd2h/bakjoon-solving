#include <iostream>

int main()
{
    int count,max,min;
    std::cin>>count;
    int numArr[count]={};

    for(int num=0;num<count;num++)
    {
        std::cin>>numArr[num];
        if(num==0)
        {
            max=min=numArr[num];
        }
        else if(numArr[num]>max)
        {
            max=numArr[num];
        }
        else if(numArr[num]<min)
        {
            min=numArr[num];
        }
    }
    std::cout<<min<<" "<<max<<std::endl;
    return 0;

}