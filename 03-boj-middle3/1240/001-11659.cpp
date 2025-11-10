#include <iostream>

using namespace std;

void makeFenwicktree(int n, int arr[], int fenwicktree[], int idx)
{
    int num=arr[idx];
    while(idx<=n)
    {
        fenwicktree[idx]+=num;
        idx=idx+(idx & -idx);
    }
}

int resultFenwicktree(int fenwicktree[], int idx)
{
    int res=0;
    while(idx)
    {
        res+=fenwicktree[idx];
        idx=idx-(idx&-idx);
    }
    return res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[100001];
    int fenwicktree[100001]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        makeFenwicktree(n,arr,fenwicktree,i);
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        int resB=resultFenwicktree(fenwicktree,b);
        int resA=resultFenwicktree(fenwicktree,a-1);
        cout<<resB-resA<<"\n";
    }
}