#include <iostream>
#include <string>

using namespace std;

void difficultContest()
{
    string s;
    cin>>s;
    int bit[26]={0};
    int ssize=s.size();
    for(int i=0;i<ssize;i++)
    {
        bit[s[i]-'A']++;
    }
    string result;
    while(bit['T'-'A'])
    {
        result+='T';
        bit['T'-'A']--;
    }
    for(int i=0;i<26;i++)
    {
        if(!bit[i]) continue;
        if(i==('T'-'A')) continue;
        while(bit[i])
        {
            result+=char(65+i);
            bit[i]--;
        }
    }
    cout<<result<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        difficultContest();
    }
}