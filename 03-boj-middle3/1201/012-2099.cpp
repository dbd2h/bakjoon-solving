#include <iostream>

using namespace std;

bool mulArr[201][201][20]={0};

void resultMaker(int n, bool result[201][201], int k, int c)
{
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                result[i][j]=mulArr[i][j][c];
            }
        }
        return;
    }
    resultMaker(n,result,k/2,c+1);
    if(k%2==0) return;
    bool resultC[201][201]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(result[i][k] && mulArr[k][j][c]) resultC[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            result[i][j]=resultC[i][j];
        }
    }
    return;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k,m;
    cin>>n>>k>>m;
    bool graph[201][201]={0};
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[i][a]=1;
        graph[i][b]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mulArr[i][j][0]=graph[i][j];
        }
    }
    for(int i=1;i<20;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int a=1;a<=n;a++)
                {
                    if(mulArr[j][a][i-1] && mulArr[a][k][i-1])
                    {
                        mulArr[j][k][i]=1;
                        break;
                    }
                }
            }
        }
    }
    bool result[201][201]={0};
    resultMaker(n,result,k,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(result[a][b]) cout<<"death\n";
        else cout<<"life\n";
    }
}