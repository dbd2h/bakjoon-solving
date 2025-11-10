#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    while(!(s.size()==1 && s[0]=='0'))
    {
        int l=0;
        int r=s.size()-1;
        bool isY=true;
        while(l<=r)
        {
            if(s[l]!=s[r])
            {
                isY=false;
                break;
            }
            l++;
            r--;
        }
        if(isY) cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
        cin>>s;
    }
}