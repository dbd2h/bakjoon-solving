#include <iostream>
#include <vector>

using namespace std;

int minHeap[100001]={0};

vector<int> result;

void changeArr(int n1, int n2)
{
    int c=minHeap[n1];
    minHeap[n1]=minHeap[n2];
    minHeap[n2]=c;
}

void minHeapInput(int len, int num)
{
    minHeap[len]=num;
    int i=len;
    while(true)
    {
        if(i/2==0 || minHeap[i/2]<minHeap[i]) break;
        changeArr(i/2,i);
        i/=2;
    }
}

void minHeapPop(int len)
{
    result.push_back(minHeap[1]);
    minHeap[1]=minHeap[len];
    minHeap[len]=0;
    int i=1;
    while(true)
    {
        if(i*2>len-1) break;
        int smaller;
        if(i*2==len-1)
        {
            smaller=i*2;
        }
        else smaller = minHeap[i*2]<minHeap[i*2+1] ? i*2 : i*2+1;
        if(minHeap[i]<minHeap[smaller]) break;
        changeArr(i,smaller);
        i=smaller;
    }
}

int main()
{
    int n;
    cin>>n;
    int len=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a==0)
        {
            if(len==0)
            {
                result.push_back(0);
                continue;
            }
            minHeapPop(len);
            len--;
        }
        else
        {
            len++;
            minHeapInput(len, a);
        }
    }
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<"\n";
    }
}