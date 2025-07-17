#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define MAX_LEN 1000

using namespace std;

int search(int used[], int n)
{
    for(int i=0;i<4;i++)
    {
        if(used[i]==0)
        {
            used[i]=n;
            return 1;
        }
        if(used[i]==n)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int map[MAX_LEN][MAX_LEN]={0};
    int count[MAX_LEN][MAX_LEN]={0};
    vector<int> bfsCount={0};
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            map[i][j]=s[j]-'0';
        }
    }
    int c=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]==0 && count[i][j]==0)
            {
                int num=0;
                queue<pair<int,int>> q;
                q.push({i,j});
                count[i][j]=c;
                while(!q.empty())
                {
                    int a,b;
                    a=q.front().first;
                    b=q.front().second;
                    num++;
                    q.pop();
                    if(a-1>=0 && map[a-1][b]==0 && count[a-1][b]==0)
                    {
                        count[a-1][b]=c;
                        q.push({a-1,b});
                    }
                    if(a+1<n && map[a+1][b]==0 && count[a+1][b]==0)
                    {
                        count[a+1][b]=c;
                        q.push({a+1,b});
                    }
                    if(b-1>=0 && map[a][b-1]==0 && count[a][b-1]==0)
                    {
                        count[a][b-1]=c;
                        q.push({a,b-1});
                    }
                    if(b+1<m && map[a][b+1]==0 && count[a][b+1]==0)
                    {
                        count[a][b+1]=c;
                        q.push({a,b+1});
                    }
                }
                bfsCount.push_back(num);
                c++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]==1)
            {
                int sumNum=1;
                int used[4]={0};
                if(i-1>=0 && search(used, count[i-1][j]))
                {
                    sumNum+=bfsCount[count[i-1][j]];
                }
                if(j-1>=0 && search(used, count[i][j-1]))
                {
                    sumNum+=bfsCount[count[i][j-1]];
                }
                if(i+1<n && search(used, count[i+1][j]))
                {
                    sumNum+=bfsCount[count[i+1][j]];
                }
                if(j+1<m && search(used, count[i][j+1]))
                {
                    sumNum+=bfsCount[count[i][j+1]];
                }
                map[i][j]=sumNum%10;
            }
            cout<<map[i][j];
        }
        cout<<"\n";
    }

}