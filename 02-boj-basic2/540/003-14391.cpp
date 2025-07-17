#include <iostream>

using namespace std;

int digit(int num, int n);
void paperCut(int (*paper)[4], int (*ox)[4], int *arr, int n, int m, int count, int nI, int mI, int *max);

int main()
{
    int n,m;
    int max=0;
    cin>>n>>m;
    int paper[4][4];
    int ox[4][4]={0};
    int arr[16];
    int input;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        for(int j=0;j<m;j++)
        {
            paper[i][j]=digit(input, m-j-1);
        }
    }
    
    paperCut(paper, ox, arr, n, m, 0, 0, 0, &max);
    cout<<max;
}

void paperCut(int (*paper)[4], int (*ox)[4], int *arr, int n, int m, int count, int nI, int mI, int *max)
{
    if(nI==n&&mI==0)
    {
        int tot=0;
        for(int i=0;i<count;i++)
        {
            tot+=arr[i];
        }
        if(tot>*max)
        {
            *max=tot;
        }
        return;
    }
    for(int i=nI;i<n;i++)
    {   
        if(ox[i][mI]==1)
        {
            break;
        }
        int num=0;
        int e=1;
        for(int j=i;j>=nI;j--)
        {
            num+=paper[j][mI]*e;
            ox[j][mI]=1;
            e*=10;
        }
        arr[count]=num;
        int n1=nI, m1=mI;
        do
        {
            if(m1<m-1)
            {
                m1++;
            }
            else
            {
                m1=0;
                n1++;
            }
            if(n1==n)
            {
                break;
            }
        } while(ox[n1][m1]==1);

        paperCut(paper, ox, arr, n, m, count+1, n1, m1, max);
        for(int j=i;j>=nI;j--)
        {
            ox[j][mI]=0;
        }
    }
    for(int i=mI+1;i<m;i++)
    {
        if(ox[nI][i]==1)
        {
            break;
        }
        int num=0;
        int e=1;
        for(int j=i;j>=mI;j--)
        {
            num+=paper[nI][j]*e;
            ox[nI][j]=1;
            e*=10;
        }
        arr[count]=num;
        int n1=nI, m1=mI;
        do
        {
            if(m1<m-1)
            {
                m1++;
            }
            else
            {
                m1=0;
                n1++;
            }
            if(n1==n)
            {
                break;
            }
        } while(ox[n1][m1]==1);
        paperCut(paper, ox, arr, n, m, count+1, n1, m1, max);
        for(int j=i;j>=mI;j--)
        {
            ox[nI][j]=0;
        }
    }
}

int digit(int num, int e)
{
    int a=1;
    for(int i=0;i<e;i++)
    {
        a*=10;
    }
    return (num%(a*10)/a);
}
