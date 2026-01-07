#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void problem(int n)
{
    int m;
    cin>>m;
    vector<int> graphP[1001];
    vector<int> graphM[1001];
    int rating[2001][2];
    int checkN[1001]={0};
    bool checkM[2001]={0};
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        rating[i][0]=a;
        rating[i][1]=b;
        if(a>0) graphP[a].push_back(i);
        else graphM[-a].push_back(i);
        if(b>0) graphP[b].push_back(i);
        else graphM[-b].push_back(i);
    }
    queue<int> q;
    bool isYes=true;
    for(int i=1;i<=n;i++)
    {
        if(checkN[i]!=0) continue;
        q.push(i);
        checkN[i]=1;
        vector<int> checkNV;
        vector<int> checkMV;
        checkNV.push_back(i);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            int pass=checkN[cur];
            for(auto &judge : graphP[cur])
            {
                if(checkM[judge]) continue;
                if(pass==1)
                {
                    checkM[judge]=1;
                    checkMV.push_back(judge);
                    continue;
                }
                int a,b;
                a=rating[judge][0];
                b=rating[judge][1];
                if(a==cur || -a==cur)
                {
                    int c=a;
                    a=b;
                    b=c;
                }
                int isP=1;
                if(a<0)
                {
                    a=-a;
                    isP=-1;
                } 
                if(checkN[a]!=0 && checkN[a]!=isP)
                { 
                    isYes=false;
                    break;
                }
                if(checkN[a]==0)
                {
                    checkN[a]=isP;
                    checkNV.push_back(a);
                    q.push(a);
                }
                checkM[judge]=1;
                checkMV.push_back(judge);
            }
            for(auto &judge : graphM[cur])
            {
                if(checkM[judge]) continue;
                if(pass==-1)
                {
                    checkM[judge]=1;
                    checkMV.push_back(judge);
                    continue;
                }
                int a,b;
                a=rating[judge][0];
                b=rating[judge][1];
                if(a==cur || -a==cur)
                {
                    int c=a;
                    a=b;
                    b=c;
                }
                int isP=1;
                if(a<0)
                {
                    a=-a;
                    isP=-1;
                } 
                if(checkN[a]!=0 && checkN[a]!=isP)
                {
                    isYes=false;
                    break;
                }
                if(checkN[a]==0)
                {
                    checkN[a]=isP;
                    checkNV.push_back(a);
                    q.push(a);
                }
                checkM[judge]=1;
                checkMV.push_back(judge);
            }
            if(!isYes) break;
        }
        if(isYes) continue;
        if(!isYes && i==1) break;
        for(auto &j : checkNV)
        {
            checkN[j]=0;
        } 
        for(auto &j : checkMV)
        {
            checkM[j]=0;
        }
        while(!q.empty()) q.pop();
        isYes=true;
        q.push(i);
        checkN[i]=-1;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            int pass=checkN[cur];
            for(auto &judge : graphP[cur])
            {
                if(checkM[judge]) continue;
                if(pass==1)
                {
                    checkM[judge]=1;
                    continue;
                }
                int a,b;
                a=rating[judge][0];
                b=rating[judge][1];
                if(a==cur || -a==cur)
                {
                    int c=a;
                    a=b;
                    b=c;
                }
                int isP=1;
                if(a<0)
                {
                    a=-a;
                    isP=-1;
                } 
                if(checkN[a]!=0 && checkN[a]!=isP)
                { 
                    isYes=false;
                    break;
                }
                if(checkN[a]==0)
                {
                    checkN[a]=isP;
                    q.push(a);
                }
                checkM[judge]=1;
            }
            for(auto &judge : graphM[cur])
            {
                if(checkM[judge]) continue;
                if(pass==-1)
                {
                    checkM[judge]=1;
                    continue;
                }
                int a,b;
                a=rating[judge][0];
                b=rating[judge][1];
                if(a==cur || -a==cur)
                {
                    int c=a;
                    a=b;
                    b=c;
                }
                int isP=1;
                if(a<0)
                {
                    a=-a;
                    isP=-1;
                } 
                if(checkN[a]!=0 && checkN[a]!=isP)
                {
                    isYes=false;
                    break;
                }
                if(checkN[a]==0)
                {
                    checkN[a]=isP;
                    q.push(a);
                }
                checkM[judge]=1;
            }
            if(!isYes) break;
        }
        if(!isYes) break;
    }
    if(isYes) cout<<"yes\n";
    else cout<<"no\n";
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while(cin>>n)
    {
        problem(n);
    }
}