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
#define LEN 200001
#define INF (int)(1e9)

using namespace std;

int arr[LEN*2];

struct TRIE
{
    TRIE *bit[2];
    bool finish;

    TRIE()
    {
        bit[0]=bit[1]=NULL;
        finish=false;
    }

    void insert(int num, int idx)
    {
        if(idx<0)
        {
            finish=true;
            return;
        } 
        int cur=1<<idx;
        if(num>=cur)
        {
            if(bit[1]==NULL) bit[1]=new TRIE();
            bit[1]->insert(num-cur,idx-1);
        }
        else
        {
            if(bit[0]==NULL) bit[0]=new TRIE();
            bit[0]->insert(num,idx-1);
        }
    }
    int minV(int num, int idx)
    {
        if(idx<0) return 0;
        int cur=1<<idx;
        if(num>=cur)
        {
            if(bit[1]==NULL) return cur+bit[0]->minV(num-cur,idx-1);
            else return bit[1]->minV(num-cur,idx-1);
        }
        else
        {
            if(bit[0]==NULL) return cur+bit[1]->minV(num,idx-1);
            else return bit[0]->minV(num,idx-1);
        }
    }
};

int resMaker(int l, int r)
{
    TRIE *Root;
    for(int i=0;i<l;i++) Root->insert(arr[i],30);
    int minV=INF;
    for(int i=l;i<r;i++)
    {
        int cur=Root->minV(arr[i],30);
        minV=min(minV,cur);
    }
    return minV;
}

int recurF(int l, int r, int idx)
{
    if(idx<0) return 0;
    int cur=1<<idx;
    int ret=0;
    if(arr[r-1]-cur<0) ret=recurF(l,r,idx-1)
    for(int i=l;i<r;i++)
    {
        if()
    }
}

int main()
{
    int n;
    cin>>n; 
    for(int i=0;i<n*2;i++) cin>>arr[i];
    sort(arr,arr+n*2);
    int res=0;
    for(int i=30;i>=0;i--)
    {
        int cur=1<<i;
        int l=lower_bound(arr,arr+n*2,cur>>1)-arr;
        int r=lower_bound(arr,arr+n*2,cur)-arr;
        if(l==r) continue;
        if((r-l)%2==0)
        {
            for(int j=l;j<r;j++) arr[j]-=cur;
        }
        else
        {
            int value=resMaker(l,r);
            res=max(res,value);
        }
    }
    cout<<res;
}