#include <iostream>

int main()
{
    int total=0;
    for(int i=0;i<5;i++)
    {
        int inputNum;
        std::cin>>inputNum;
        total+=inputNum*inputNum;
    }
    std::cout<<total%10<<"\n";
}