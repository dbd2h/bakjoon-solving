#include <iostream>
#include <string>

using namespace std;

int main()
{
    int l;
    string s;
    cin>>l;
    cin>>s;
    int kmp[1000000]={0};
    int i=0;
    int j=1;
    int slen=s.size();
    while(j<slen)
    {
        if(s[i]==s[j])
        {
            kmp[j]=++i;
            j++;
        }
        else if(i!=0)
        {
            i=kmp[i-1];
        }
        else
        {
            kmp[j]=0;
            j++;
        }
    }

    cout<<slen-kmp[slen-1];
}