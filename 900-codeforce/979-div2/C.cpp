#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int test=0;test<t;test++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int alice=0;
        int bob=0;
        int last=0;
        if(s[0]=='1' || s[n-1]=='1') alice=200000;
        for(int i=0;i<n;i++)
        {
            int num=s[i]-'0';
            if(last && num)
            {
                alice=200000;
                break;
            }
            if(num) alice++;
            else bob++;
            last=num;
            if(alice>n) break;
            if(bob>n) break;
        }
        if(alice>=bob) cout<<"YES\n";
        else cout<<"NO\n"; 
    }   
}

