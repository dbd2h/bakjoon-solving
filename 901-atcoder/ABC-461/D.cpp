#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;

using namespace std;

int main()
{
    int h,w,k;
    cin>>h>>w>>k;
    bool arr[501][501]={0};
    for(int i=1;i<=h;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=w;j++)
        {
            arr[i][j]=s[j-1]-'0';
        }
    }
    int sumArr[501][501]={0};
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            sumArr[i][j]=sumArr[i-1][j]+arr[i][j];
        }
    }
    ll res=0;
    for(int lo=0;lo<h;lo++)
    {
        for(int hi=lo+1;hi<=h;hi++)
        {
            ll rowArr[501];
            rowArr[0]=0;
            for(int i=1;i<=w;i++) rowArr[i]=rowArr[i-1]+(ll)(sumArr[hi][i]-sumArr[lo][i]);
            int r1=1;
            int r2=1;
            for(int l=0;l<w;l++)
            {
                r1=max(r1,l+1);
                r2=max(r2,l+1);
                while(r1<=w && rowArr[r1]-rowArr[l]<k) r1++;
                while(r2<=w && rowArr[r2]-rowArr[l]<=k) r2++;
                res+=(ll)(r2-r1);
            }
        }
    }
    cout<<res;
}