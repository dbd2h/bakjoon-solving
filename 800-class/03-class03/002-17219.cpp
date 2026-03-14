#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<string, string> addM;
    int n,m;
    cin>>n>>m;
    string s1,s2;
    for(int i=0;i<n;i++)
    {
        cin>>s1>>s2;
        addM[s1]=s2;
    }
    for(int j=0;j<m;j++)
    {
        string s;
        cin>>s;
        cout<<addM[s]<<"\n";
    }
}