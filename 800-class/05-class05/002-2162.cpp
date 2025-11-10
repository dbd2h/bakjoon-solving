#include <iostream>
#include <queue>

using namespace std;

int line[3000][4]={0};

long long cp(int a1, int b1, int a2, int b2)
{
    return a1*b2-b1*a2;
}

bool ccw(int n1, int n2)
{
    long long cp1=cp(line[n1][0]-line[n1][2],line[n1][1]-line[n1][3],line[n1][0]-line[n2][0],line[n1][1]-line[n2][1]);
    long long cp2=cp(line[n1][0]-line[n1][2],line[n1][1]-line[n1][3],line[n1][0]-line[n2][2],line[n1][1]-line[n2][3]);
    long long cp12=cp1*cp2;
    if(cp12>0) return false;
    long long cp3=cp(line[n2][0]-line[n2][2],line[n2][1]-line[n2][3],line[n2][0]-line[n1][0],line[n2][1]-line[n1][1]);
    long long cp4=cp(line[n2][0]-line[n2][2],line[n2][1]-line[n2][3],line[n2][0]-line[n1][2],line[n2][1]-line[n1][3]);
    long long cp34=cp3*cp4;
    if(cp34>0) return false;
    if(cp1==cp2 && cp2==cp3 && cp3==cp4 && cp1==0)
    {
        if(line[n1][0]==line[n1][2] && line[n1][2]==line[n2][0] && line[n2][0]==line[n2][2])
        {
            if((line[n1][1]-line[n2][1])*(line[n1][1]-line[n2][3])<=0 || (line[n1][3]-line[n2][1])*(line[n1][3]-line[n2][3])<=0)
            {
                return true;
            }
            else if((line[n2][1]-line[n1][1])*(line[n2][1]-line[n1][3])<=0 || (line[n2][3]-line[n1][1])*(line[n2][3]-line[n1][3])<=0)
            {
                return true;
            }
            else return false;
        }
        if((line[n1][0]-line[n2][0])*(line[n1][0]-line[n2][2])<=0 || (line[n1][2]-line[n2][0])*(line[n1][2]-line[n2][2])<=0)
        {
            return true;
        }
        else if((line[n2][0]-line[n1][0])*(line[n2][0]-line[n1][2])<=0 || (line[n2][2]-line[n1][0])*(line[n2][2]-line[n1][2])<=0)
        {
            return true;
        }
        else return false;
    }
    if(cp12<=0 && cp34<=0) return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>line[i][j];
        }
    }
    if(n==1)
    {
        cout<<1<<"\n"<<1;
        return 0;
    }
    int g=1;
    int group[3000]={0};
    for(int i=0;i<n;i++)
    {
        if(group[i]!=0) continue;
        group[i]=g;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(int j=0;j<n;j++)
            {
                if(group[j]!=0) continue;
                bool isGroup=ccw(cur,j);
                if(isGroup)
                {
                    q.push(j);
                    group[j]=g;
                }
            }
        }
        g++;
    }
    int bit[3001]={0};
    int maxG=0;
    for(int i=0;i<n;i++)
    {
        bit[group[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(maxG<bit[i]) maxG=bit[i];
    }
    cout<<g-1<<"\n"<<maxG;
}