#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    bool graph[401][401]={0};
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(graph[j][i] && graph[i][k]) graph[j][k]=1;
            }
        }
    }
    int s;
    cin>>s;
    for(int i=0;i<s;i++)
    {
        int a,b;
        cin>>a>>b;
        if(graph[a][b]) cout<<-1;
        else if(graph[b][a]) cout<<1;
        else cout<<0;
        cout<<"\n";
    }
}