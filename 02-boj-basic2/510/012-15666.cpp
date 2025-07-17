#include <iostream>

using namespace std;

void print(int *rArr, int *iArr, int n, int k, int count, int index);
void insert_sort(int *iArr, int len);

int main()
{
    int n,k;
    int resultArr[8]={0};
    int inputArr[8]={0};
    cin>>n>>k;
    int index=0;
    int input;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        for(int j=0;j<index;j++)
        {
            if(inputArr[j]==input)
            {
                input=0;
                break;
            }
        }
        if(input!=0)
        {
            inputArr[index]=input;
            index++;
        }
    }
    insert_sort(inputArr, index);
    print(resultArr, inputArr, index, k, 0, 0);

}

void print(int *rArr, int *iArr, int n, int k, int count, int index)
{
    if(count==k)
    {
        for(int i=0;i<k;i++)
        {
            cout<<rArr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=index;i<n;i++)
    {
        rArr[count]=iArr[i];
        print(rArr,  iArr, n, k, count+1, i);
    }
}

void insert_sort(int *iArr, int len)
{
    for(int i=0;i<len;i++)
    {
        int min=iArr[i];
        int minI=i;
        for(int j=i+1;j<len;j++)
        {
            if(min>iArr[j])
            {
                min=iArr[j];
                minI=j;
            }
        }
        int c=iArr[i];
        iArr[i]=min;
        iArr[minI]=c;
    }
}