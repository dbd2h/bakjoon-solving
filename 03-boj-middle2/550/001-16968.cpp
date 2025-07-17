#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int res=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='c')
        {
            if(i==0 || s[i-1]=='d') res*=26;
            else res*=25;
        }
        else
        {
            if(i==0 || s[i-1]=='c') res*=10;
            else res*=9;
        }
    }
    cout<<res;
}