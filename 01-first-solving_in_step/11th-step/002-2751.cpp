#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int numArr[2000001]={0};
    int million=1000000;

    for(int i=0;i<inputNum;i++)
    {
        int sortNum;
        std::cin>>sortNum;
        numArr[sortNum+million]++;
    }
    for(int i=0;i<sizeof(numArr)/sizeof(int);i++)
    {
        if(numArr[i]==1)
        {
            std::cout<<i-million<<"\n";
        }
    }
    return 0;
}