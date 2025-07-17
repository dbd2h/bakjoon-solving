#include <iostream>

int w[10]={0};
int maxNum=0;
int p[10]={0};
int wSet[10]={0};

using namespace std;

void energyGain(int n, int cur)
{
    if(cur==n-2)
    {
        int result=0;
        int isUsed[10]={0};
        for(int i=0;i<n-2;i++)
        {
            int index=p[i];
            int x=index-1;
            int y=index+1;
            isUsed[index]=1;
            while(isUsed[x])
                x--;
            while(isUsed[y])
                y++;
            result+=w[x]*w[y];
        }
        if(maxNum<result)
        {
            maxNum=result;
        }
        return;
    }
    for(int i=1;i<n-1;i++)
    {
        if(wSet[i]==1)
        {
            continue;
        }
        p[cur]=i;
        wSet[i]=1;
        energyGain(n, cur+1);
        wSet[i]=0;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    energyGain(n, 0);
    cout<<maxNum;
}