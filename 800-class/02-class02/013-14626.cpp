#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int m=s[12]-'0';
    int idx=-1;
    int tot=0;
    for(int i=0;i<12;i++)
    {
        if(s[i]=='*')
        {
            idx=i;
            continue;
        }
        int cur=s[i]-'0';
        if(i%2==0) tot+=cur;
        else tot+=cur*3;
    }
    for(int i=0;i<10;i++)
    {
        int mul=1;
        if(idx%2==1) mul=3;
        if((tot+mul*i)%10==(10-m)%10)
        {
            cout<<i;
            break;
        }
    }
}