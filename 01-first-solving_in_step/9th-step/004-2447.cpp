#include <iostream>
#include <string>

void starLineMaker(std::string *arr,int num)
{
    std::string preArr[num+1];
    if(num!=1)
    {
        starLineMaker(preArr,num/2);
    }
    else
    {
        preArr[0]='*';
        preArr[1]=' ';
    }
    for(int j=0;j<num;j++)
    {
        arr[2*j]=preArr[j]+preArr[j]+preArr[j];
        arr[2*j+1]=preArr[j]+preArr[num]+preArr[j];
    }
    arr[num*2]=preArr[num]+preArr[num]+preArr[num];
    return;
}

int starPointer(int line, int len)
{
    if(line/3==0)
    {
        if(line==0)
        {
            return 0;
        }
        if(line==1)
        {
            return len;
        }
        if(line==2)
        {
            return 0;
        }
    }
    else
    {
        if(line%3==0)
        {
            line/=3;
            return starPointer(line,len/2);
        }
        if(line%3==1)
        {
            line/=3;
            return len+starPointer(line,len/2);
        }
        if(line%3==2)
        {
            line/=3;
            return starPointer(line,len/2);
        }
    }
    return 1;
}

void starPointMaker(int num)
{
    int powNum=1;
    int pow3Num=1;
    for(int i=0;i<num;i++)
    {
        powNum*=2;
        pow3Num*=3;
    }
    std::string preStar[powNum+1];
    starLineMaker(preStar,powNum/2);
    for(int i=0;i<pow3Num;i++)
    {
        int a=starPointer(i,powNum/2);
        std::cout<<preStar[a]<<std::endl;
    }
}

int main()
{
    int a;
    std::cin>>a;
    int squaA=0;
    while(a!=1)
    {
        a/=3;
        squaA++;
    }
    starPointMaker(squaA);
}