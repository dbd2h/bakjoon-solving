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
#define LEN 1000001

using namespace std;

int stabArr[LEN];
int arr[LEN];


void program()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>stabArr[i];
    for(int i=1;i<=n*m;i++) cin>>arr[i];
    priority_queue<int> pq;
    int res=m;
    for(int i=n;i>=1;i--)
    {
        for(int j=i*m;j>=i*m-m+1;j--)
        {
            pq.push(arr[j]);
        }
        vector<int> output;
        int c=0;
        int stab=stabArr[i];
        while(c<m)
        {
            stab-=pq.top();
            c++;
            output.push_back(pq.top());
            pq.pop();
            if(stab<=0) break;
        }
        res=min(res,c);
        for(int j=0;j<output.size();j++) pq.push(output[j]);
    }
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}