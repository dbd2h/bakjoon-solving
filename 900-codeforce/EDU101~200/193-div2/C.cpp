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
#define LEN 200001

using namespace std;

int aArr[LEN];
int bArr[LEN];

void program()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>aArr[i];
    } 
    for(int i=1;i<=b;i++)
    {
        cin>>bArr[i];
    }
    int ac=0;
    int bc=0;
    int bi=0;
    ll res=0;
    while(ac+bc+bi<n+m-1 && (a>=1 || b>=1))
    {
        if(a>=1 && ac<n)
        {
            if(b>=1 && bc<m)
            {
                if(aArr[a]==bArr[b])
                {
                    res+=aArr[a];
                    a--;
                    b--;
                    bi++;
                }
                else if(aArr[a]>bArr[b])
                {
                    res+=aArr[a];
                    a--;
                    ac++;
                }
                else
                {
                    res+=bArr[b];
                    b--;
                    bc++;
                }
            }
            else
            {   
                res+=aArr[a];
                a--;
                ac++;
            }
        }
        else if(b>=1 && bc<m)
        {
            res+=bArr[b];
            b--;
            bc++;
        }
        else break;
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