#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;
    int idx=0;
    for(int i=0;i<3;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
        if(s[0]-'0'>=0 && s[0]-'0'<=9)
        {
            int num=0;
            int ten=1;
            for(int j=s.size()-1;j>=0;j--)
            {
                num+=ten*(s[j]-'0');
                ten*=10;
            }
            idx=num+(3-i);
        }
    }
    string res;
    if(idx%3==0)
    {
        res+="Fizz";
    }
    if(idx%5==0)
    {
        res+="Buzz";
    }
    if(res.size()==0) cout<<idx;
    else cout<<res;
}