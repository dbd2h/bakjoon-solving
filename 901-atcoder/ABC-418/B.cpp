#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int slen=s.size();
    long double result=0;
    for(int i=0;i<slen-2;i++)
    {
        string res;
        if(s[i]!='t') continue;
        int c=0;
        for(int j=i;j<slen;j++)
        {
            res+=s[j];
            int reslen=res.size();
            if(s[j]!='t') continue;
            else c++;
            if(c<3) continue;
            long double rate=( (long double)c-2)/( (long double)reslen-2);
            if(result<rate) result=rate;
        }
    }
    cout<<fixed;
    cout.precision(20);
    cout<<result;
}