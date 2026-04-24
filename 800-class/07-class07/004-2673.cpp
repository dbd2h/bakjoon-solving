#include <iostream>
#include <vector>

using namespace std;

void recurF(bool isCrossed[50][50], bool check[50], int n, int idx, int c, int *res)
{
    for(int i=idx;i<n;i++)
    {
        if(c+(n-i)<=(*res)) return;
        if(check[i]) continue;
        int arr[50];
        int arrLen=0;
        for(int j=i+1;j<n;j++)
        {
            if(check[j]) continue;
            if(isCrossed[i][j])
            {
                check[j]=1;
                arr[arrLen]=j;
                arrLen++;
            }
        }
        recurF(isCrossed,check,n,i+1,c+1,res);
        for(int j=0;j<arrLen;j++)
        {
            check[arr[j]]=0;
        }
    }
    if((*res)<c) (*res)=c;
}

int main()
{
    int n;
    cin>>n;
    int lineArr[50][2];
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
        {
            int c=a;
            a=b;
            b=c;
        }
        lineArr[i][0]=a;
        lineArr[i][1]=b;
    }
    bool isCrossed[50][50];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(lineArr[i][0]<lineArr[j][0])
            {
                if(lineArr[i][1]<lineArr[j][0] || lineArr[i][1]>lineArr[j][1]) isCrossed[i][j]=0;
                else isCrossed[i][j]=1;
            }
            else
            {
                if(lineArr[j][1]<lineArr[i][0] || lineArr[j][1]>lineArr[i][1]) isCrossed[i][j]=0;
                else isCrossed[i][j]=1;
            }
        }
    }
    int res=0;
    bool check[50]={0};
    recurF(isCrossed,check,n,0,0,&res);
    cout<<res;
}