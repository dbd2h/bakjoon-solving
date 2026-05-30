#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 3001

using namespace std;

void program()
{
    int n,table,seat;
    cin>>n>>table>>seat;
    string s;
    cin>>s;
    
    int res=0;
    int arr[LEN];
    arr[0]=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='I') arr[i+1]=1;
        else if(s[i]=='E') arr[i+1]=2;
        else if(s[i]=='A') arr[i+1]=3;
    }
    for(int i=0;i<=n;i++)
    {
        if(i!=0 && arr[i]!=3) continue;
        if(i!=0) arr[i]=1;
        int curSum=0;
        int curT=0;
        int curS=0;
        for(int j=1;j<=n;j++)
        {
            if(arr[j]==1)
            {
                if(table<=curT) continue;
                curT++;
                curSum++;
                curS+=(seat-1);
            }
            else
            {
                if(curS==0) continue;
                curSum++;
                curS--;
            }
        }
        res=max(res,curSum);
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