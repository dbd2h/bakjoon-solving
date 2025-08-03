#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> kmp;

int main()
{
    string s;
    cin>>s;
    kmp.push_back(0);
    int i=0;
    int j=1;
    int ssize=s.size();
    if(ssize<3)
    {
        cout<<-1;
        return 0;
    }
    while(j<ssize)
    {
        if(s[i]==s[j])
        {
            kmp.push_back(++i);
            j++;
        }
        else if(i!=0)
        {
            i=kmp[i-1];
        }
        else
        {
            kmp.push_back(0);
            j++;
        }
    }
    int maxV=0;
    if(kmp[ssize-1]==ssize-1)
    {
        cout<<s.substr(0,ssize-2);
        return 0;
    }
    int result=kmp[ssize-1];
    for(int idx=0;idx<ssize-1;idx++)
    {
        if(kmp[idx]>maxV) maxV=kmp[idx];
    }
    while(result>maxV)
    {
        result=kmp[result-1];
    }
    if(result==0)
    {
        cout<<-1;
        return 0;
    }
    cout<<s.substr(0,result);
}