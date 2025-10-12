#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;
 
using namespace std;
 
void program()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=0;
    int b=0;
    vector<int> firstV;
    vector<int> lastV;
    firstV.push_back(0);
    lastV.push_back(0);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a') a++;
        else if(s[i]=='b') b++;
        if(a==b) firstV.push_back(i+1);
    }
    a=0;
    b=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='a') a++;
        else if(s[i]=='b') b++;
        if(a==b) lastV.push_back(n-i);
    }
    if(firstV.size()==1 && lastV.size()==1)
    {
        cout<<-1<<"\n";
        return;
    }
    int res=-1;
    int idx=lastV.size()-1;
    for(int i : firstV)
    {
        while(idx>0)
        {
            int j=lastV[idx];
            if(i+j>n)
            {
                idx--;
                continue;
            }
            break;
        }
        int cur=i+lastV[idx];
        if(res==-1 || res<cur) res=cur;
    }
    cout<<n-res<<"\n";
}   
 
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}