#include <iostream>
#include <string>

using namespace std;

void count(int arr[], int one, int two, int idx, int *res)
{
    if(idx==10)
    {
        if(!(one==0 && two==0)) return;
        (*res)++;
        cout<<(*res)<<". ";
        for(int i=0;i<10;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    count(arr,one,two,idx+1,res);
    if((idx==0 || arr[idx-1]==0) && two!=0)
    {
        arr[idx]=2;
        count(arr,one,two-1,idx+1,res);
        arr[idx]=0;
    }
    if((idx==0 || arr[idx-1]!=2) && one!=0)
    {
        arr[idx]=1;
        count(arr,one-1,two,idx+1,res);
        arr[idx]=0;
    }
}

int main()
{
    int arr[10]={0};
    int res=0;
    count(arr,4,2,0,&res);
    cout<<res;
}