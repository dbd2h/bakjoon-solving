#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(pair<int,int>p1, pair<int,int>p2)
{
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first>p2.first;
}

void problem(int n, int m)
{
    bool matrix[1000][1000]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    short matrixCol[1000][1000]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!matrix[i][j]) continue;
            if(matrixCol[i][j]) continue;
            int c=0;
            for(int k=i;k<n;k++)
            {
                if(!matrix[k][j]) break;
                c++;
            }
            int k=i;
            while(c)
            {
                matrixCol[k][j]=c;
                c--;
                k++;
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        vector<pair<int,int>> v;
        int check[1000][2]={0};
        for(int j=0;j<m;j++)
        {
            v.push_back({matrixCol[i][j],j});
            check[j][0]=-1;
        }
        sort(v.begin(),v.end(),compare);
        for(int j=0;j<m;j++)
        {
            int h=v[j].first;
            if(!h) break;
            if(h*m<=res) break;
            int idx=v[j].second;
            int l=idx;
            int r=idx;
            if(idx-1>=0 && check[idx-1][0]!=-1) l=check[idx-1][0];
            if(idx+1<m && check[idx+1][0]!=-1) r=check[idx+1][1];
            int w=r-l+1;
            if(res<h*w) res=h*w;
            check[l][0]=l;
            check[l][1]=r;
            check[r][0]=l;
            check[r][1]=r;
        }

    }
    cout<<res<<"\n";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true)
    {   
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0) break;
        problem(n,m);
    }
}