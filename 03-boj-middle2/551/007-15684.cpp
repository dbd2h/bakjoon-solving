#include <iostream>

using namespace std;

int ladder[30][9]={0};
int ladderS[31][10]={0};

void ladderBatch(int n, int ch)
{
    for(int i=0;i<n;i++)
    {
        ladderS[ch][i]=ladderS[ch-1][i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(ladder[ch-1][i]==1)
        {
            int c=ladderS[ch][i];
            ladderS[ch][i]=ladderS[ch][i+1];
            ladderS[ch][i+1]=c;
        }
    }
}

void dfs(int n, int m, int h, int c, int *minV, int s)
{
    if(c==3)
    {
        int a=s/n;
        int b=s%n;
        if(b!=0) a++;
        for(int i=a;i<=h;i++)
        {
            ladderBatch(n,i);
        }
        int isC=1;
        for(int i=0;i<n;i++)
        {
            if(i+1!=ladderS[h][i])
            {
                isC=0;
                break;
            }
        }
        if(isC) *minV=3;
        return;
    }
    for(int i=s;i<(n-1)*h;i++)
    {
        if(*minV!=-1 && *minV <= c) return;
        int a=i/(n-1);
        int b=i%(n-1);
        if(b==0 && a!=0)
        {
            ladderBatch(n,a);
        }
        if(ladder[a][b]==1) continue;
        if(b!=0 && ladder[a][b-1]==1) continue;
        if(b!=n-1 && ladder[a][b+1]==1) continue;
        if(*minV==-1 || *minV > c+1)
        {
            ladder[a][b]=1;
            dfs(n,m,h,c+1,minV,i+1);
            ladder[a][b]=0;
        }
    }
    ladderBatch(n,h);
    int isC=1;
    for(int i=0;i<n;i++)
    {
        if(i+1 != ladderS[h][i])
        {
            isC=0;
        }
    }
    if(isC) *minV=c;
    return;
    
}

int main()
{
    int n,m,h;
    cin>>n>>m>>h;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        ladder[a-1][b-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        ladderS[0][i]=i+1;
    }
    int minV=-1;
    dfs(n,m,h,0,&minV,0);
    cout<<minV;
}