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
#define LEN 41

using namespace std;

lld arr[LEN];

int bs(int l, int r, int n)
{
    int mid=(l+r)/2;
    lld mean=mid;
    mean/=n;
    lld cArr[LEN];
    for(int i=1;i<=n;i++)
    {
        cArr[i]=arr[i]-mean;
    }
    
}

int main()
{
    int n,t;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {

    }
}