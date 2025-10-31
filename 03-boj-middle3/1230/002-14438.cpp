#include <iostream>

using namespace std;

int makeSegmentTree(int n, int arr[], int segTree[], int l, int r, int idx)
{
    int mid=(l+r)/2;
    if(l==r)
    {
        segTree[idx]=arr[l];
        return arr[l];
    }
    int num1=makeSegmentTree(n,arr,segTree,l,mid,idx*2);
    int num2=makeSegmentTree(n,arr,segTree,mid+1,r,idx*2+1);
    int next=num1;
    if(next>num2) next=num2;
    segTree[idx]=next;
    return next;
}

int findSegmentTree(int n, int segTree[], int l, int r, int idx, int a, int b)
{
    
    if(b<l || r<a) return -1;
    else if(l==r) return segTree[idx];
    else if(a<=l && r<=b) return segTree[idx];
    else
    {
        int num1=findSegmentTree(n,segTree,l,(l+r)/2,idx*2,a,b);
        int num2=findSegmentTree(n,segTree,(l+r)/2+1,r,idx*2+1,a,b);
        if(num1==-1) return num2;
        else if(num2==-1) return num1;
        return num1<num2 ? num1 : num2;
    }
}

void changeSegmentTree(int n, int segTree[], int l, int r, int idx, int num, int i)
{
    if(l==r)
    {
        segTree[idx]=num;
        return;
    }
    int mid=(l+r)/2;
    if(mid>=i)
    {
        changeSegmentTree(n,segTree,l,mid,idx*2,num,i);
    }
    else if(mid<i)
    {
        changeSegmentTree(n,segTree,mid+1,r,idx*2+1,num,i);
    }
    segTree[idx]=segTree[idx*2]>segTree[idx*2+1] ? segTree[idx*2+1] : segTree[idx*2];
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[100001];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int segTree[400001];
    makeSegmentTree(n,arr,segTree,1,n,1);

    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            changeSegmentTree(n,segTree,1,n,1,c,b);
        }
        else if(a==2)
        {
            int res=findSegmentTree(n,segTree,1,n,1,b,c);
            cout<<res<<"\n";
        }
    }
}