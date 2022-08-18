#include <iostream>

void change(long long *arr, long long index1, long long index2)
{
    long long change=arr[index1];
    arr[index1]=arr[index2];
    arr[index2]=change;
}

int binarySearch(long long *arr,int first,int last,long long search)
{
    int half=(first+last)/2;
    if(arr[half]==search)
    {
        return half;
    }
    else if(arr[half]>search)
    {
        return binarySearch(arr,first,half-1,search);
    }
    else
    {
        return binarySearch(arr,half+1,last,search);
    }
}

int main()
{
    int inputNum;
    std::cin>>inputNum;
    long long numArr[inputNum]={0};
    long long oriArr[inputNum]={0};
    for(int i=0;i<inputNum;i++)
    {
        long long num;
        std::cin>>num;
        numArr[i]=num;
        oriArr[i]=num;
        int cur=i;
        while(cur-1)
        {
            if(numArr[cur-1]>numArr[cur/2-1])
            {
                change(numArr,cur-1,cur/2-1);
                cur/=2;
            }
            else
            {
                break;
            }
        }
    }
    change(numArr,0,inputNum-1);
    int final=inputNum-1;
    for(int i=inputNum-1;i>0;i--)
    {
        int tree=1;
        while(tree<=i/2)
        {   
            if(numArr[tree*2-1]>=numArr[tree*2]||tree*2==i)
            {
                if(numArr[tree*2-1]>numArr[tree-1])
                {
                    change(numArr,tree*2-1,tree-1);
                    tree=tree*2;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(numArr[tree*2]>numArr[tree-1])
                {
                    change(numArr,tree*2,tree-1);
                    tree=tree*2+1;
                }
                else
                {
                    break;
                }
            }
        }
        change(numArr,0,i-1);
        change(numArr,final-1,i-1);
        if(numArr[final-1]!=numArr[final])
        {
            final--;
        }
    }
    for(int i=0;i<inputNum;i++)
    {   
        std::cout<<binarySearch(numArr,final,inputNum-1,oriArr[i])-final<<" ";
    }
}