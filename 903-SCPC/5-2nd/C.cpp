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

int A[LEN][2];
int B[LEN][2];
vector<pair<pair<int,int>,pair<int,int>>> v;

ll resMaker(bool isUp, int bef, int idx, int startH, int curH)
{
    priority_queue<pair<int,int>> pq; // height, Lidx
    for(int i=bef+1;i<=idx;i++)
    {
        if(!isUp) pq.push({v[i].first.second,v[i].second.second});
        else pq.push({-v[i].first.first,v[i].second.second});
    }
    if(isUp)
    {
        startH=-startH;
        curH=-curH;
    }
    ll tot=0;
    int maxH=startH;
    int minH=pq.top().first;
    int r=pq.top().second;
    pq.pop();
    for(int i=bef+1;i<=idx;i++)
    {
        int l=v[i].second.second;
        if(l>r)
        {
            while(!pq.empty())
            {
                minH=pq.top().first;
                r=pq.top().second;
                pq.pop();
                if(l<=r) break;
            }
        }
        int up=v[i].first.first;
        if(isUp)up=-v[i].first.second;
        if(up<maxH) maxH=up;
        else up=maxH;
        int down=minH;
        if(curH>down) down=curH;
        ll len=v[i].second.first;
        tot+=len*(up-down);
    }
    return tot;
}

void program()
{
    v.clear();
    int len,startP,endP;
    cin>>len>>startP>>endP;
    int a,b;
    cin>>a;
    for(int i=0;i<a;i++) cin>>A[i][0]>>A[i][1];
    cin>>b;
    for(int i=0;i<b;i++) cin>>B[i][0]>>B[i][1];
    int aL,bL,aI,bI;
    aI=bI=0;
    aL=A[aI][0];
    bL=B[bI][0];
    int totLen=0;
    while(aI<a)
    {
        int aH=A[aI][1];
        int bH=B[bI][1];
        int curLen=min(aL,bL);
        totLen+=curLen;
        v.push_back({{aH,bH},{curLen,totLen}});
        aL-=curLen;
        bL-=curLen;
        if(aL==0)
        {
            aI++;
            if(aI==a) break;
            aL=A[aI][0];
        }
        if(bL==0)
        {
            bI++;
            bL=B[bI][0];
        }
    }
    v.push_back({{endP,endP},{1,totLen+1}});
    int bef=-1;
    int idx=-1;
    bool isUp=false;
    int firstH=startP;
    int curH=startP;
    ll res=0;
    for(int i=0;i<=v.size();i++)
    {   
        if(i==v.size())
        {
            res+=resMaker(isUp,bef,i-1,firstH,curH);
            break;
        }
        pair<pair<int,int>,pair<int,int>> p=v[i];
        int up=p.first.first;
        int down=p.first.second;
        if(up<curH)
        {
            if(idx==-1)
            {
                idx=i;
                isUp=false;
                curH=up;
                continue;
            }
            else if(!isUp)
            {
                idx=i;
                curH=up;
                continue;
            }
            res+=resMaker(isUp,bef,idx,firstH,curH);
            bef=idx;
            idx=i;
            isUp=false;
            firstH=curH;
            curH=up;
        }
        else if(down>curH)
        {
            
            if(idx==-1)
            {
                idx=i;
                isUp=true;
                curH=down;
                continue;
            }
            else if(isUp)
            {
                idx=i;
                curH=down;
                continue;
            }
            res+=resMaker(isUp,bef,idx,firstH,curH);
            bef=idx;
            idx=i;
            isUp=true;
            firstH=curH;
            curH=down;
        }
    }
    cout<<res<<endl;
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