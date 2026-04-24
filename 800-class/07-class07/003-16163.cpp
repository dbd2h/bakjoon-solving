#include <iostream>
#include <string>
#include <algorithm>
#define LEN 4000003

using namespace std;

int main()
{
    string s,ss;
    cin>>s;
    int slen=s.size();
    ss='#';
    for(int i=0;i<slen;i++)
    {
        ss+=s[i];
        ss+='#';
    }
    int pArr[LEN];
    int p=0;
    int r=0;
    int totLen=ss.size();
    for(int i=0;i<totLen;i++)
    {
        if(i<r) pArr[i]=min(pArr[p-(i-p)],r-i);
        else pArr[i]=0;
        while(pArr[i]<i && i+pArr[i]<totLen-1 && ss[i+pArr[i]+1]==ss[i-pArr[i]-1]) pArr[i]++;
        if(i+pArr[i]>r)
        {
            r=i+pArr[i];
            p=i;
        }
    }
    long long res=0;
    for(int i=0;i<totLen;i++)
    {
        res+= (long long) ((pArr[i]+1)/2);
    }
    cout<<res;
}