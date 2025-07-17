#include <iostream>
#include <vector>

using namespace std;

int maxHeap[100001]={0};

vector<int> result;

void changeArr(int n1, int n2)
{
    int c=maxHeap[n1];
    maxHeap[n1]=maxHeap[n2];
    maxHeap[n2]=c;
}

void maxHeapInput(int len, int num)
{
    maxHeap[len]=num;
    int i=len;
    while(true)
    {
        if(i/2==0 || maxHeap[i/2]>maxHeap[i]) break;
        changeArr(i/2,i);
        i/=2;
    }
}

void maxHeapPop(int len)
{
    result.push_back(maxHeap[1]);
    maxHeap[1]=maxHeap[len];
    maxHeap[len]=0;
    int i=1;
    while(true)
    {
        if(i*2>len) break;
        int bigger;
        if(i*2==len)
        {
            bigger=i*2;
        }
        bigger = maxHeap[i*2]>maxHeap[i*2+1] ? i*2 : i*2+1;
        if(maxHeap[i]>maxHeap[bigger]) break;
        changeArr(i,bigger);
        i=bigger;
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
            maxHeapPop(len);
            len--;
        }
        else
        {
            len++;
            maxHeapInput(len, a);
        }
    }
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<"\n";
    }
}