#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int numArr[inputNum];
    int dpAsc[inputNum];
    int dpDesc[inputNum];
    int finMax=0;

    for(int i=0;i<inputNum;i++)
    {
        std::cin>>numArr[i];
        int max=1;
        for(int j=i-1;j>=0;j--)
        {
            if(numArr[i]>numArr[j]&&max<dpAsc[j]+1)
            {
                max=dpAsc[j]+1;
            }
        }
        dpAsc[i]=max;
    }
    for(int i=0;i<inputNum;i++)
    {
        int max=1;
        int std=inputNum-i-1;
        for(int j=std+1;j<inputNum;j++)
        {
            if(numArr[std]>numArr[j]&&max<dpDesc[j]+1)
            {
                max=dpDesc[j]+1;
            }
        }
        dpDesc[std]=max;
        if(finMax<dpDesc[std]+dpAsc[std]-1)
        {
            finMax=dpDesc[std]+dpAsc[std]-1;
        }
    }
    std::cout<<finMax<<"\n";
}