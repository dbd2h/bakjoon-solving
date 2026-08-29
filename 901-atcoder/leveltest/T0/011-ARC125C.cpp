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

vector<int> v;

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    int len=v.size();
    int bef=0;
    for(int i=0;i<len;i++)
    {
        int cur=v[i];
        if(i==len-1)
        {
            for(int j=n;j>cur;j--) cout<<j<<" ";
        }
        for(int j=cur;j>bef;j--) cout<<j<<" ";
        bef=cur;
    }
}