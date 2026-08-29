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
#define LEN 3001

using namespace std;

bool arr[LEN][LEN]={0};
int sumArr[LEN][LEN];

int main()
{
    int h,w,n;
    cin>>h>>w>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
    }
    for(int y=1;y<=w;y++)
    {
        int l=1;
        int r=1;
        while(l<=h)
        {
            while(r<=h && arr[r][y]==0) r++;
            while(l<r)
            {
                sumArr[l][y]=r-l;
                l++;
            }
            l++;
            r++;
        }
    }
    ll res=0;
    for(int x=1;x<=h;x++)
    {
        int l=0;
        int r=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        while(r<=w)
        {
            while(!pq.empty() && pq.top().second<l) pq.pop();
            if(l==r)
            {
                r++;
                if(r<=w)
                {
                    if(sumArr[x][r]==0) l++;
                    else pq.push({sumArr[x][r],r});
                }
                continue;
            }
            
            if(r>=w || min(pq.top().first,sumArr[x][r+1])<r-l+1)
            {
                res+=(r-l);
                l++;
            }
            else
            {
                r++;
                pq.push({sumArr[x][r],r});
            }
        }
    }
    cout<<res;
}