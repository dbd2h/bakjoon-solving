#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;

    int numArr[inputNum]={0};

    for(int i=0;i<inputNum;i++)
    {
        std::cin>>numArr[i];
    }

    for(int i=0;i<inputNum;i++)
    {
        int num=numArr[i];
        int min=numArr[i];
        int index=i;
        for(int j=i;j<inputNum;j++)
        {
            if(min>numArr[j])
            {
                min=numArr[j];
                index=j;
            }
        }
        numArr[i]=min;
        numArr[index]=num;
    }

    for(int i=0;i<inputNum;i++)
    {
        std::cout<<numArr[i]<<"\n";
    }
}