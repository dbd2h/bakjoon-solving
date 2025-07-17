#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> graph[100001];

int binarySearch(int l, int r, int start, int end, int n)
{
    int middle=(l+r)/2;
    int middleN=middle+1;
    while(l<r)
    {
        middle=(l+r)/2;
        middleN=middle+1;
        int check[100001]={0};
        int finish=0;
        queue<int> q;
        q.push(start);
        check[start]=1;
        while(!q.empty())
        {
            int island = q.front();
            q.pop();
            for(int i=0;i<graph[island].size();i++)
            {
                pair<int,int> next=graph[island][i];
                if(check[next.first]==1 || next.second<middle) continue;
                if(next.first==end)
                {
                    finish=1;
                    break;
                }
                q.push(next.first);
                check[next.first]=1;
            }
            if(finish==1) break;
        }
        while(!q.empty()) q.pop();
        int finish2=0;
        int check2[100001]={0};
        q.push(start);
        check2[start]=1;
        while(!q.empty())
        {
            int island = q.front();
            q.pop();
            for(int i=0;i<graph[island].size();i++)
            {
                pair<int,int> next=graph[island][i];
                if(check2[next.first]==1 || next.second<middleN) continue;
                if(next.first==end)
                {
                    finish2=1;
                    break;
                }
                q.push(next.first);
                check2[next.first]=1;
            }
            if(finish2==1) break;
        }
        if(finish==1 && finish2==0) return middle;
        else if(finish==1)
        {
            l=middle+1;
        }
        else r=middle-1;
    }
    return r;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int start,end;
    cin>>start>>end;
    cout<<binarySearch(1,1000000000,start,end,n);
}