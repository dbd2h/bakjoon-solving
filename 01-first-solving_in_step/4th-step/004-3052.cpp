#include <iostream>

int main()
{
    int remainArr[10]={0};
    int maxIndex=0;

    for(int count=0;count<10;count++)
    {
        bool isInArr=false;
        int inputNum;
        std::cin>>inputNum;
        inputNum%=42;
        for(int index=0;index<maxIndex;index++)
        {
            if(remainArr[index]==inputNum)
            {
                isInArr=true;
                break;
            }
        }
        if(!isInArr)
        {
            remainArr[maxIndex]=inputNum;
            maxIndex++;
        }
    }
    std::cout<<maxIndex<<"\n";
}