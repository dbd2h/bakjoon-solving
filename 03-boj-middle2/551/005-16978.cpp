#include <iostream>

using namespace std;

int egg[8][2]={0};

int isCrashed[8]={0};

void eggCrash(int n, int c, int *maxN)
{
    if(n==c)
    {
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=isCrashed[i];
        }
        if(res>*maxN) *maxN = res;
        return;
    }
    if(isCrashed[c]==1)
    {
        eggCrash(n,c+1,maxN);
        return;
    } 
    int isC=0;
    for(int i=0;i<n;i++)
    {
        if(c==i) continue;
        if(isCrashed[i]) continue;
        isC=1;
        egg[i][0]-=egg[c][1];
        egg[c][0]-=egg[i][1];
        if(egg[i][0]<=0) isCrashed[i]=1;
        if(egg[c][0]<=0) isCrashed[c]=1;
        eggCrash(n,c+1,maxN);
        isCrashed[i]=0;
        isCrashed[c]=0;
        egg[i][0]+=egg[c][1];
        egg[c][0]+=egg[i][1];
    }
    if(isC==0)
    {
        eggCrash(n,c+1,maxN);
        return;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>egg[i][0];
        cin>>egg[i][1];
    }
    int res=0;
    eggCrash(n,0,&res);
    cout<<res;
}