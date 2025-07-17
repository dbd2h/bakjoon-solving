#include <iostream>

using namespace std;

int arr[100000]={0};
int arrP[100000]={0};

int abs(int n)
{
    if(n<0) n=-n;
    return n;
}

//dis: arr[i+1]-arr[i]
void brute(int n, int c, int op, int dis, int *minN)
{
    if(c==0)
    {
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                arrP[0]=i;
                arrP[1]=j;
                brute(n,c+2,abs(i)+abs(j),arr[1]+arrP[1]-arr[0]-arrP[0],minN);
                for(int k=0;k<n;k++)
                {
                    arrP[k]=0;
                }
            }
        }
        return;
    }
    for(int i=2;i<n;i++)
    {
        int curDis=arr[i]-(arr[i-1]+arrP[i-1]);
        if(curDis-dis>1 || curDis-dis<-1) return;
        if(curDis-dis==1)
        {
            arrP[i]=-1;
            op++;
        }
        else if(curDis-dis==-1)
        {
            arrP[i]=1;
            op++;
        }
    }
    if(*minN==-1 || *minN>op)
    {
        *minN=op;
    }
    
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(n==1 || n==2)
    {
        cout<<0;
        return 0;
    }
    int result=-1;
    brute(n,0,0,0,&result);
    cout<<result;
}