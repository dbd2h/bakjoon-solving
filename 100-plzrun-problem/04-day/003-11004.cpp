#include <iostream>

void change(int arr[], int i1, int i2)
{
    int c=arr[i1];
    arr[i1]=arr[i2];
    arr[i2]=c;
}

void heapInput(int arr[], int len)
{
    while(len!=1)
    {
        if(arr[len/2-1]>arr[len-1])
        {
            change(arr,len/2-1,len-1);
        }
        else
        {
            return;
        }
        len/=2;
    }
    return;
}

int main()
{
    int len,k;
    std::cin>>len>>k;
    int numArr[len];
    std::ios_base::sync_with_stdio(false);  
    std::cin.tie(NULL);
    for(int i=0;i<len;i++)
    {
        std::cin>>numArr[i];
        heapInput(numArr,i+1);
    }
    for(int i=0;i<k-1;i++)
    {
        int realSize=len-i-1;
        int start=1;
        change(numArr,0,realSize);
        while(start<=realSize/2)
        {
            if(start*2==realSize)
            {
                if(numArr[start-1]>numArr[start*2-1])
                {
                    change(numArr,start-1,start*2-1);
                }
                break;
            }
            else
            {
                if(numArr[start*2-1]<numArr[start*2])
                {
                    if(numArr[start-1]>numArr[start*2-1])
                    {
                        change(numArr,start-1,start*2-1);
                    }
                    else
                    {
                        break;
                    }
                    start=start*2;
                }
                else
                {
                    if(numArr[start-1]>numArr[start*2])
                    {
                        change(numArr,start-1,start*2);
                    }
                    else
                    {
                        break;
                    }
                    start=start*2+1;
                }
            }
        }
    }
    std::cout<<numArr[0]<<"\n";
}

// heap정렬 쓰기