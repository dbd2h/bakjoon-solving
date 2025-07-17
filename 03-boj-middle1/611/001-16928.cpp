#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    int move[101]={0};
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n+m;i++)
    {
        int num;
        cin>>num;
        cin>>move[num];
    }

    queue<pair<int,int>> q;
    q.push({1,0});
    int result;
    int isfinish=0;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        int pos, count;
        pos=p.first;
        count=p.second;
        for(int i=1;i<=6;i++)
        {
            if(pos+i==100)
            {
                result=count+1;
                isfinish=1;
                break;
            }
            if(move[pos+i]==0)
            {
                if(i==6)
                {
                    q.push({pos+i, count+1});
                }
                else if(move[pos+i+1]!=0)
                {
                    q.push({pos+i, count+1});
                }
            }   
            else
            {
                if(move[pos+i]<count*3)
                {
                    continue;
                }
                q.push({move[pos+i], count+1});
            }
        }
        if(isfinish)
        {
            break;
        }
    }
    cout<<result;
}