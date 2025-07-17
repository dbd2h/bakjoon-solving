#include <iostream>

using namespace std;

void print(int *tArr, int *pArr, int n, int index, int *max, int now);

int main()
{
    int n;
    cin>>n;
    int tArr[n+1];
    int pArr[n+1];
    int max=0;
    for(int i=1;i<=n;i++)
    {
        cin>>tArr[i]>>pArr[i];
    }
    print(tArr,pArr,n,1,&max,0);
    cout<<max;
}

void print(int *tArr, int *pArr, int n, int index, int *max, int now)
{
    if(index>n)
    {
        if(now>*max)
        {
            *max=now;
        }
        return;
    }
    for(int i=index;i<=n;i++)
    {
        if(tArr[i]+i-1>n)
        {
            print(tArr,pArr,n,tArr[i]+i,max,now);
        }
        else
        {
            print(tArr,pArr,n,i+tArr[i],max,now+pArr[i]);
        }
    }
}