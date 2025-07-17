#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    map<string,int> smap;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        smap[s]++;
    }
    int result=0;
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        if(smap[s]!=0) result++;
    }
    cout<<result;
}