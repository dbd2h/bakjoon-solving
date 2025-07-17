#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int slen=s.size();
    int kmp[5000]={0};
    
    int result=0;
    for(int start=0;start<slen;start++)
    {   
        int i=0;
        int j=1;
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
        for(int i=0;i<slen-start;i++)
        {
            if(result<kmp[i]) result=kmp[i];
        }
        s=s.substr(1);
    }
    cout<<result;
}