#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 200001

using namespace std;

void program()
{
    ll n,table,seat;
    cin>>n>>table>>seat;
    string s;
    cin>>s;
    
    ll res=0;
    int arr[LEN];
    arr[0]=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='I') arr[i+1]=1;
        else if(s[i]=='E') arr[i+1]=2;
        else if(s[i]=='A') arr[i+1]=3;
    }
    ll A=0;
    ll curS=0;
    ll curT=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==1)
        {
            if(table<=curT) continue;
            res++;
            curT++;
            curS+=(seat-1);
        }
        else if(arr[i]==2)
        {
            if(curS==0)
            {
                if(A<=0 || table<=curT) continue;
                A--;
                curT++;
                curS+=(seat-1);
                res++;
            }
            else
            {
                curS--;
                res++;
            }
        }
        else if(arr[i]==3)
        {
            if(curS>0)
            {
                A++;
                curS--;
                res++;
                continue;
            }
            if(curS==0 && curT<table)
            {
                curT++;
                curS+=(seat-1);
                res++;
            }
        }
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