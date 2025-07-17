#include <iostream>

using namespace std;

int noTo[201][201]={0};

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        noTo[a][b]=1;
        noTo[b][a]=1;
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(noTo[i][j]==1) continue;
            for(int k=j+1;k<=n;k++)
            {
                if(noTo[i][k]==1 || noTo[j][k]==1) continue;
                res++;
            }
        }
    }
    cout<<res;
}