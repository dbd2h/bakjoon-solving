#include <iostream>

int main()
{
    int n,m;
    std::cin>>n>>m;
    int inputArr[n]={0};
    for(int i=0;i<n;i++)
    {
        std::cin>>inputArr[i];
    }
    int diffMax=inputArr[0]+inputArr[1]+inputArr[2];
    int result=inputArr[0]+inputArr[1]+inputArr[2];
    if(diffMax<0)
    {
        diffMax=-diffMax;
    }
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int diff=m-(inputArr[i]+inputArr[j]+inputArr[k]);
                if(diff<0)
                {
                    continue;
                }
                if(diffMax>diff)
                {
                    diffMax=diff;
                    result=inputArr[i]+inputArr[j]+inputArr[k];
                }
            }
        }
    }
    std::cout<<result<<std::endl;
}