#include <iostream>

void hanoi(int size,int from,int empty,int to)
{
    if(size!=1)
    {
        hanoi(size-1,from,to,empty);
        std::cout<<from<<" "<<to<<"\n";
        hanoi(size-1,empty,from,to);
    }
    else
    {
        std::cout<<from<<" "<<to<<"\n";
    }
}

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int doubleNum=1;
    for(int i=0;i<inputNum;i++)
    {
        doubleNum*=2;
    }
    std::cout<<doubleNum-1<<std::endl;
    hanoi(inputNum,1,2,3);
}