#include <iostream>
#include <string>

using namespace std;

int coin[20][20]={0};
int isflip[20]={0};

void flipper(int n, int now, int *m)
{
    if(now!=n)
    {
        flipper(n,now+1,m);
        isflip[now]=1;
        flipper(n,now+1,m);
        isflip[now]=0;
        return;
    }
    int val=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+= isflip[j] ? !coin[i][j] : coin[i][j];
        }
        if(sum > n-sum) val+=n-sum;
        else val+=sum;
    }
    if(val < *m) *m=val;
    return;
}

int main()
{
    int n;
    cin>>n;
    int m=4000;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++) coin[i][j] = s[j]=='H' ? 0 : 1;
    }
    flipper(n,0,&m);
    cout<<m;
}