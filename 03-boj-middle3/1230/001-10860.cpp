#include <iostream>
#include <vector>

using namespace std;

pair<int,int> segmentBinary(int arr[], int segTree[][2], int l, int r, int idx)
{   
    pair<int,int> p1={-1,-1};
    pair<int,int> p2={-1,-1};
    if(l>r) return {-1,-1};
    if(l==r)
    {
        segTree[idx][0]=arr[l];
        segTree[idx][1]=arr[r];
        return {arr[l],arr[r]};
    }
    p1=segmentBinary(arr,segTree,l,(l+r)/2,idx*2);
    p2=segmentBinary(arr,segTree,(l+r)/2+1,r,idx*2+1);
    int maxV=p1.first;
    int minV=p1.second;
    if(p2.first>maxV) maxV=p2.first;
    if(p2.second<minV) minV=p2.second;
    segTree[idx][0]=maxV;
    segTree[idx][1]=minV;
    return {maxV,minV};
}

pair<int,int> segmentResult(int segTree[][2], int l, int r, int idx, int a, int b)
{
    int mid=(l+r)/2;
    pair<int,int> p1={-1,-1}, p2={-1,-1};
    if(l>b || a>r) return {-1,-1};
    else if(a<=l && r<=b) return {segTree[idx][0],segTree[idx][1]};
    else
    {
        p1=segmentResult(segTree,l,mid,idx*2,a,b);
        p2=segmentResult(segTree,mid+1,r,idx*2+1,a,b);
        if(p1.first==-1)
        {
            return p2;
        }
        else if(p2.first==-1)
        {
            return p1;
        }
        else
        {
            if(p1.first<p2.first) p1.first=p2.first;
            if(p1.second>p2.second) p1.second=p2.second;
            return p1;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[100001];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int segTree[400001][2];
    segmentBinary(arr,segTree,1,n,1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        pair<int,int> res=segmentResult(segTree,1,n,1,a,b);
        cout<<res.second<<"\n";
    }
}