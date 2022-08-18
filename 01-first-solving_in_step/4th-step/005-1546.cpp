#include <iostream>

int main()
{
    int n;
    float total=0;
    std::cin>>n;
    float numArr[n]={0};
    float max;
    for(int count=0;count<n;count++)
    {
        std::cin>>numArr[count];
        if(count==0)
        {
            max=numArr[count];
        }
        else if(numArr[count]>max)
        {
            max=numArr[count];
        }
    }
    for(int index=0;index<n;index++)
    {
        total+=numArr[index]/max*100;
    }
    std::cout<<total/n<<std::endl;
}