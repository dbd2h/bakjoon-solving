#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;

    int dungchiArr[inputNum][3]={0};
    for(int i=0;i<inputNum;i++)
    {
        std::cin>>dungchiArr[i][0];
        std::cin>>dungchiArr[i][1];
        dungchiArr[i][2]++;
    }
    
    for(int i=0;i<inputNum;i++)
    {
        for(int j=0;j<inputNum;j++)
        {
            if(dungchiArr[i][0]<dungchiArr[j][0])
            {
                if(dungchiArr[i][1]<dungchiArr[j][1])
                {
                    dungchiArr[i][2]++;
                }
            }
        }
        if(i!=0)
        {
            std::cout<<" ";
        }
        std::cout<<dungchiArr[i][2];
    }
}