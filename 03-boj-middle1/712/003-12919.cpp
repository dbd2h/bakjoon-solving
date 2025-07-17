#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int check(string t)
{
    if(s.length()==t.length())
    {
        if(s==t) return 1;
        else return 0;
    }
    int len=t.length();
    if(t[len-1]=='A')
    {
        if(check(t.substr(0,len-1)))
        {
            return 1;
        }
    }
    if(t[0]=='B')
    {
        string ss;
        for(int i=1;i<=len-1;i++)
        {
            ss+=t[len-i];
        }
        if(check(ss))
        {
            return 1;
        }
    }
    return 0;

}

int main()
{
    string t;
    cin>>s>>t;
    cout<<check(t);
    
}