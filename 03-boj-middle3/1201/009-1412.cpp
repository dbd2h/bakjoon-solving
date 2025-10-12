#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    bool graph[50][50]={0};
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='Y') graph[i][j]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(!(graph[i][j] && graph[j][i])) continue;
            graph[i][j]=0;
            graph[j][i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(graph[j][i] && graph[i][k]) graph[j][k]=1;
            }
        }
    }
    bool isC=false;
    for(int i=0;i<n;i++)
    {
        if(graph[i][i])
        {
            isC=true;
            break;
        }
    }
    if(isC) cout<<"NO";
    else cout<<"YES";
}