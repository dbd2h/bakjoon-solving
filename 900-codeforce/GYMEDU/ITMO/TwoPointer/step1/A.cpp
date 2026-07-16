#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 100001
#define INF (1e9+7)

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int A[LEN];
    int B[LEN];
    int res[LEN*2];
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<m;i++) cin>>B[i];
    int idxA=0;
    int idxB=0;
    int idx=0;
    while(idxA<n && idxB<m)
    {
        if(A[idxA]<B[idxB])
        {
            res[idx]=A[idxA];
            idxA++;
        }
        else
        {
            res[idx]=B[idxB];
            idxB++;
        }
        idx++;
    }

    while(idxA<n)
    {
        res[idx]=A[idxA];
        idx++;
        idxA++;
    }
    while(idxB<m)
    {
        res[idx]=B[idxB];
        idx++;
        idxB++;
    }
    for(int i=0;i<n+m;i++) cout<<res[i]<<" ";
}