#include <iostream>

int numberPlus(int number){
    int sum=number;
    while(number!=0)
    {
        sum+=number%10;
        number/=10;
    }
    return sum;
}

int main()
{
    int notSelfNumArr[10000]={1};
    for(int count=1;count<=9980;count++)
    {
        if(numberPlus(count)<10000)
        {
            notSelfNumArr[numberPlus(count)]=1;
        }
    }
    for(int count=1;count<10000;count++)
    {
        if(!notSelfNumArr[count])
        {
            std::cout<<count<<"\n";
        }
    }
    return 0;
}