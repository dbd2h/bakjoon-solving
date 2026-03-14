#include <iostream>
#include <vector>

using namespace std;

int abs(int num)
{
    if(num<0) num=-num;
    return num;
}

void changeValue(int heapArr[], int idx1, int idx2)
{
    int c=heapArr[idx1];
    heapArr[idx1]=heapArr[idx2];
    heapArr[idx2]=c;
}

bool cmp(int heapArr[], int idx1, int idx2)
{
    int num1=abs(heapArr[idx1]);
    int num2=abs(heapArr[idx2]);
    if(num1>num2 || (num1==num2 && heapArr[idx1]>0 && heapArr[idx2]<0))
    {
        return true;
    }
    else return false;
}

void heapInsert(int len, int heapArr[], int num)
{
    heapArr[len]=num;
    int idx=len/2;
    while(idx)
    {
        if(cmp(heapArr,idx,len))
        {
            changeValue(heapArr,idx,len);
            len=idx;
            idx=len/2;
        }
        else break;
    }
}

void heapDelete(int len, int heapArr[])
{
    changeValue(heapArr, 1, len+1);
    if(len==0) return;
    int idx=1;
    while(idx*2<=len)
    {
        if(idx*2==len || cmp(heapArr,idx*2+1,idx*2))
        {
            if(cmp(heapArr,idx,idx*2))
            {
                changeValue(heapArr,idx,idx*2);
                idx=idx*2;
            } 
            else break;
        }
        else
        {
            if(cmp(heapArr,idx,idx*2+1))
            {
                changeValue(heapArr,idx,idx*2+1);
                idx=idx*2+1;
            } 
            else break;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int len=0;
    int heapArr[100001];
    vector<int> resV;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(num==0)
        {
            if(len==0)
            {
                resV.push_back(0);
                continue;
            }
            resV.push_back(heapArr[1]);
            len--;
            heapDelete(len,heapArr);
        }
        else
        {
            len++;
            heapInsert(len,heapArr,num);
        }
    }
    int vlen=resV.size();
    for(int i=0;i<vlen;i++)
    {
        cout<<resV[i]<<"\n";
    }
}