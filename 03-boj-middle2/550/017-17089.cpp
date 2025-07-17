#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[4001];

int vSize[4001]={0};

bool findV(int l, int r, int num, int i)
{
    if(l>r) return false;
    int middle=(l+r)/2;
    if(v[i][middle]==num) return true;
    else if(v[i][middle]>num) return findV(l,middle-1,num,i);
    else return findV(middle+1,r,num,i);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        vSize[a]++;
        vSize[b]++;
    }
    for(int i=0;i<4001;i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    int minV=-1;
    for(int i=1;i<4001;i++)
    {
        for(int j=0;j<vSize[i];j++)
        {
            int f1=v[i][j];
            if(i>f1) continue;
            for(int k=0;k<vSize[f1];k++)
            {
                int f2=v[f1][k];
                if(f1>f2) continue;
                if(findV(0,vSize[i]-1,f2,i))
                {
                    int s=vSize[i]+vSize[f1]+vSize[f2]-6;
                    if(s<minV ||  minV==-1)
                    {
                        minV=s;
                    } 
                }
            }
        }
    }
    cout<<minV;
}