#include <iostream>

int main()
{
    int test;
    std::cin>>test;

    for(int testCount=0;testCount<test;testCount++)
    {
        int height, width, num, forho, backho;
        std::cin>>height>>width>>num;

        forho=num%height;
        backho=num/height+1;
        if(forho==0)
        {
            forho=height;
            backho--;
        }


        std::cout<<100*forho+backho<<std::endl;
    }
    return 0;
}