#include <iostream>

int main()
{
    int students, price;
    std::cin>>students>>price;
    int priceArr[price]={0};

    for(int i=0;i<students;i++)
    {
        int inputNum;
        std::cin>>inputNum;
        for(int j=0;j<price;j++)
        {
            if(priceArr[j]<inputNum)
            {
                for(int k=price-1;k>j;k--)
                {
                    priceArr[k]=priceArr[k-1];
                }
                priceArr[j]=inputNum;
                break;
            }
        }
    }
    std::cout<<priceArr[price-1]<<"\n";
}