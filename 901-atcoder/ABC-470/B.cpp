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

using namespace std;

int main()
{
    int n;
    cin>>n;
    int bit[101]={0};
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        bit[num]++;
    }
    int maxV=0;
    for(int i=1;i<=n;i++)
    {
        maxV=max(maxV,bit[i]);
    }
    cout<<n-maxV;
}