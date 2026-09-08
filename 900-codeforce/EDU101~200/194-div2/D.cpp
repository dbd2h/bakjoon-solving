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

void program()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    char bef=NULL;
    char cur='0';
    int c=0;
    int res=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]==cur)
        {
            if(cur=='0')
            {
                cout<<-1<<"\n";
                return;
            }
            c++;
            continue;
        }
        if(cur=='0')
        {
            bef=cur;
            cur=s[i];
            c=1;
            continue;
        }
        if(bef=='0')
        {
            if(s[i]=='0')
            {
                if(c%2==1) res=max(res,1);
                else res=max(res,2);
            }
            else
            {
                res=max(res,2);
            }
        }
        else
        {
            if(s[i]=='0')
            {
                res=max(res,2);
            }
            else
            {
                if(c%2==1 || c>2) res=max(res,2);
                else res=max(res,3);
            }
        }
        bef=cur;
        cur=s[i];
        c=1;
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