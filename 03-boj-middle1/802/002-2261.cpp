#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int,int>> v;

int distance(pair<int,int> p1, pair<int,int> p2)
{
    int x=p1.first-p2.first;
    int y=p1.second-p2.second;
    return (x*x+y*y);
}

bool compare2(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second>p2.second;
}

int dac(int n, int st)
{
    if(n==1) return -1;
    else if(n==2) return distance(v[st],v[st+1]);
    int min=-1;
    int num=dac(n/2,st);
    if(num<min || min==-1) min=num;
    num=dac(n-n/2,st+n/2);
    if(num<min || min==-1) min=num;
    int center=st+n/2-1;
    int x=(v[center].first+v[center+1].first)/2;
    if(min==-1)
    {
        for(int i=st;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d=distance(v[i], v[j]);
                if(min==-1 || min>d) min=d;
            }
        }
    }
    else
    {
        vector<pair<int,int>> v1;
        pair<int,int> p;
        for(int i=center;i>=st;i--)
        {
            p=v[i];
            if(distance(p,{x,p.second})>=min) break;
            v1.push_back(p);
        }
        for(int i=center+1;i<st+n;i++)
        {
            p=v[i];
            if(distance(p,{x,p.second})>=min) break;
            v1.push_back(p);
        }
        sort(v1.begin(), v1.end(), compare2);
        int len=v1.size();
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                pair<int,int> p1,p2;
                p1=v1[i];
                p2=v1[j];
                if(distance({0,p1.second}, {0,p2.second})>=min) break;
                int d=distance(p1,p2);
                if(d<min)min=d;
            }
        }
    }
    return min;
}

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first==p2.first) return p1.second < p2.second;
    return p1.first<p2.first;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), compare);
    int minV=dac(n,0);
    cout<<minV;
}