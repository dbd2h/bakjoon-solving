#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 100001

using namespace std;

vector<pair<int,pair<int,int>>> v;
int tree[LEN*4];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqUp;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqDown;

void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node]=0;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update(int node, int l, int r, int idx, int num)
{
    if(l==r)
    {
        tree[node]=num;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int idx)
{
    if(idx==0) return 0;
    if(idx<l) return 0;
    else if(r<=idx) return tree[node];
    int mid=(l+r)/2;
    return query(node*2,l,mid,idx)+query(node*2+1,mid+1,r,idx);
}

int cmp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    if(p1.first==p2.first) return p1.second.first<p2.second.first;
    return p1.first<p2.first;
}

int bs(int l, int r, int num, int n)
{
    if(l>r) return r+1;
    int mid=(l+r)/2;
    int findN=query(1,1,n,mid); 
    if(findN-num==0)  return bs(mid+1,r,num,n);
    else return bs(l,mid-1,num,n);
}

void program()
{
    int n,m;
    cin>>n>>m;
    v.clear();
    build(1,1,n);
    pqUp=priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>();
    pqDown=priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>();
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        pqUp.push({a,i});
        pqDown.push({b,i});
    }
    for(int i=0;i<m;i++)
    {
        int idx,l,r;
        cin>>idx>>l>>r;
        v.push_back({idx,{l,r}});
    }
    sort(v.begin(),v.end(),cmp);
    ll res=0;
    ll resC=0;
    for(int i=0;i<m;)
    {
        int idx=v[i].first;
        int l=i;
        int r=i;
        i++;
        while(i<m)
        {
            if(v[i].first!=idx) break;
            r=i;
            i++;
        }
        while(!pqUp.empty())
        {
            if(pqUp.top().first>idx) break;
            update(1,1,n,pqUp.top().second,1);
            pqUp.pop();
        }
        while(!pqDown.empty())
        {
            if(pqDown.top().first>=idx) break;
            update(1,1,n,pqDown.top().second,0);
            pqDown.pop();
        }
        int right=0;
        int c=0;
        for(int j=l;j<=r;j++)
        {
            pair<int,int> p=v[j].second;
            ll num;
            if(right>=p.second) continue;
            else if(p.first<=right)
            {
                num=query(1,1,n,p.second)-query(1,1,n,right);
                if(num==0) continue;
            }
            else
            {
                num=query(1,1,n,p.second)-query(1,1,n,p.first-1);
                if(num==0) continue;
                if(num!=0 && (query(1,1,n,p.first-1)-query(1,1,n,right)>0 || c==0)) c++;
            }
            right=max(right,p.second);
            res+=num;
        }
        resC+=c;
    }
    cout<<res<<" "<<resC<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}       