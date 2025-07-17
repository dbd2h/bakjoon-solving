#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int s2len=s2.length();
    int s2start=0;
    int isflip=0;
    while(s1.length()!=s2len)
    {
        char st;
        if(!isflip)
        {
            st=s2[s2start+s2len-1];
            if(st=='B')
            {
                isflip=!isflip;
            }
        }
        else
        {
            st=s2[s2start];
            if(st=='B')
            {
                isflip=!isflip;
            }
            s2start++;
        }
        s2len--;
    }
    int index;
    if(isflip)
    {
        index=s2start+s2len-1;
    }
    else
    {
        index=s2start;
    }
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]!=s2[index])
            {
                cout<<0;
                return 0;
            }
        if(isflip) index--;
        else index++;
    }
    cout<<1<<"\n";
}