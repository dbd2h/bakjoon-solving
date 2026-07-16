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

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int A[LEN];
    int B[LEN];
    int res[LEN];
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<m;i++) cin>>B[i];
    int idxA=0;
    for(int i=0;i<m;i++)
    {
        while(idxA<n)
        {
            if(A[idxA]<B[i]) idxA++;
            else break;
        }
        res[i]=idxA;
    }
    for(int i=0;i<m;i++) cout<<res[i]<<" ";
}