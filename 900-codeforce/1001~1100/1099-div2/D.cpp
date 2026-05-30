#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

#define LEN 200001

using namespace std;

void program()
{
    int n;
    cin>>n;
    ll INF=-1e12;
    bool bitA[LEN];
    ll arrA[LEN];
    ll arrC[LEN];
    ll lArr[LEN];
    ll uArr[LEN];
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        int cur=s[i]-'0';
        bitA[i]=cur;
        cin>>arrA[i];
    }
    for(int i=1;i<=n;i++) cin>>arrC[i];
    for(int i=1;i<=n;i++)
    {
        lArr[i]=INF;
        uArr[i]=arrC[i];
    }
    lArr[0]=0;
    uArr[0]=0;
    bool isF=false;
    for(int i=1;i<=n;i++)
    {
        if(bitA[i])
        {
            lArr[i]=lArr[i-1]+arrA[i];
            uArr[i]=uArr[i-1]+arrA[i];
        }
        uArr[i]=min(uArr[i],arrC[i]);
        if(lArr[i]>arrC[i] || uArr[i]<arrC[i])
        {
            isF=true;
            break;
        }
        if(arrC[i]>arrC[i-1])
        {
            lArr[i]=arrC[i];
            uArr[i]=arrC[i];
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}