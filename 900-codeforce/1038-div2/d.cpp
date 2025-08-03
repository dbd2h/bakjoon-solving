#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void trafficLight()
{
    int n,m;
    cin>>n>>m;
    vector<int> v[5001];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{1,0},{0,0}}); // x, c, wc, wcs
    int wait[5001][2]={0}; // c, wc
    int answerc,answerwc;
    answerc=-1;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int c=q.front().first.second;
        int wc=q.front().second.first;
        int wcs=q.front().second.second;
        q.pop();
        if(answerc!=-1 && answerc!=c) break;
        if(x==n)
        {
            if(answerc==-1)
            {
                answerc=c;
                answerwc=wc;
            }
            else if(answerwc>wc)
            {
                answerwc=wc;
            }
        }
        if(c!=0 && wait[x][0]==c && wait[x][1]<=wc) continue;
        int vsize=v[x].size();
        int next=v[x][c%vsize];
        if(wait[next][0]==c && wait[next][1]<wc) continue;
        q.push({{next,c+1},{wc,0}});
        if((wc-wcs)/vsize==1) continue;
        if(wcs==0) wcs=c;
        q.push({{x,c+1},{wc+1,wcs}});
        wait[x][0]=c;
        wait[x][1]=wc;
    }
    cout<<answerc<<" "<<answerwc<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        trafficLight();
    }
}

