#include <iostream>

int downPlus(int height,int width)
{
    if(height==0)
    {
        return width;
    }
    else
    {
        int total=0;
        for(int i=1;i<=width;i++)
        {
            total+=downPlus(height-1,i);
        }
        return total;
    }
}

int main()
{
    int count;
    std::cin>>count;
    for(int i=0;i<count;i++)
    {
        int height, width;
        std::cin>>height>>width;
        std::cout<<downPlus(height,width)<<std::endl;
    }
    return 0;
}
