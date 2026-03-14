#include <iostream>
#include <string>
#include <vector>

using namespace std;

void problem()
{
    string p,s;
    int n;
    cin>>p>>n>>s;
    int sLen=s.size();
    int tot=0;
    vector<int> v;
    for(int i=1;i<sLen;i++)
    {
        if(n==0) break;
        if(s[i]==',' || s[i]==']')
        {
            v.push_back(tot);
            tot=0;
            continue;
        }
        tot*=10;
        tot+=s[i]-'0';
    }
    int l=0;
    int r=v.size();
    bool isRight=1;
    int pLen=p.size();
    bool isF=false;
    for(int i=0;i<pLen;i++)
    {
        if(p[i]=='R')
        {
            isRight=!isRight;
            continue;
        }
        if(l>=r)
        {
            isF=true;
            break;
        }
        if(isRight)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    if(isF)
    {
        cout<<"error"<<"\n";
    }
    else
    {
        cout<<'[';
        if(isRight)
        {
            for(int i=l;i<r;i++)
            {
                cout<<v[i];
                if(i==r-1) break;
                cout<<',';
            }
        }
        else
        {
            for(int i=r-1;i>=l;i--)
            {
                cout<<v[i];
                if(i==l) break;
                cout<<',';
            }
        }
        cout<<"]\n";
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}