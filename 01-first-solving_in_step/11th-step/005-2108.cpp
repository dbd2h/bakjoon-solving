#include <iostream>
#include <math.h>

void changeNode(int *arr, int index1, int index2)
{
    int change=arr[index1];
    arr[index1]=arr[index2];
    arr[index2]=change;
}

int main()
{
    int inputNum=5;
    std::cin>>inputNum;
    int total=0;
    int meanValue;
    int centerValue;
    int modeValue;
    int range;

    int numberArr[inputNum]={0};
    for(int i=0;i<inputNum;i++)
    {
        int num;
        std::cin>>num;
        total+=num;
        numberArr[i]=num;
        int cur=i+1;

        while(cur-1)
        {
            if(numberArr[cur-1]>numberArr[cur/2-1])
            {
                changeNode(numberArr,cur-1,cur/2-1);
            }
            else
            {
                break;
            }
            cur/=2;
        }
    }

    for(int len=inputNum;len>0;len--)
    {
        int tree=1;
        changeNode(numberArr,0,len-1);
        while((len+1)/2>tree)
        {
            if(numberArr[tree*2-1]>=numberArr[tree*2]||len==tree*2+1)
            {
                if(numberArr[tree*2-1]>numberArr[tree-1])
                {
                    changeNode(numberArr,tree*2-1,tree-1);
                }
                else
                {
                    break;
                }
                tree=tree*2;
            }
            else
            {
                if(numberArr[tree*2]>numberArr[tree-1])
                {
                    changeNode(numberArr,tree*2,tree-1);
                }
                else
                {
                    break;
                }
                tree=tree*2+1;
            }
        }
    }
    centerValue=numberArr[(inputNum-1)/2];
    range=numberArr[inputNum-1]-numberArr[0];
    int max=0;
    int cur=numberArr[0];
    bool isFirst=true;
    int hap=1;
    for(int i=1;i<inputNum;i++)
    {
        if(cur==numberArr[i])
        {
            hap++;
        }
        else
        {
            if(hap>max)
            {
                max=hap;
                modeValue=numberArr[i-1];
                isFirst=true;
            }
            else if(hap==max&&isFirst)
            {
                modeValue=numberArr[i-1];
                isFirst=false;
            }
            hap=1;
            cur=numberArr[i];
        }
        
    }
    if(hap>max)
    {
        modeValue=numberArr[inputNum-1];
    }
    else if(hap==max&&isFirst)
    {
        modeValue=numberArr[inputNum-1];
    }
    meanValue=round((double)total/inputNum);
    std::cout<<meanValue<<std::endl;
    std::cout<<centerValue<<std::endl;
    std::cout<<modeValue<<std::endl;
    std::cout<<range<<std::endl;
}