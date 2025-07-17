#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> v1,v2;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v1.push_back(s);
    }
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        v2.push_back(s);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int index=0;
    int result=0;
    for(int i=0;i<m;i++)
    {
        string s=v2[i];
        while(index<v1.size() && s>v1[index])
        {
            index++;
        }
        while(index<v1.size() && s<=v1[index])
        {
            
            string s2=v1[index];
            int slen=s.size();
            int s2len=s2.size();
            if(s2len<slen)
            {
                break;
            }
            if(s2.substr(0,slen)==s)
            {
                
                result++;
            }
            break;
        }
    }
    cout<<result;
}