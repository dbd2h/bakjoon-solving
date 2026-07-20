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
    if(s[n-1]=='A')
    {
        bool isB=false;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='B')
            {
                if(isB)
                {
                    cout<<"NO\n";
                    return;
                }
                else isB=true;
            }
            else isB=false;
        }
    }
    else if(s[n-1]=='B')
    {
        bool isA=false;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='A')
            {
                if(isA)
                {
                    cout<<"NO\n";
                    return;
                }
                else isA=true;
            }
            else isA=false;
        }   
    }
    else if(s[n-1]=='C')
    {
        cout<<"NO\n";
        return;
    } 
    cout<<"YES\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}