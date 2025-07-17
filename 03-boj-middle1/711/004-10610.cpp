#include <iostream>
#include <string>

using namespace std;

int main()
{
    int bit[10]={0};
    string s;
    cin>>s;
    int tot=0;
    for(int i=0;i<s.size();i++)
    {
        bit[s[i]-'0']++;
        tot+=(s[i]-'0');
    }
    if(bit[0]==0 || tot%3!=0)
    {
        cout<<-1;
        return 0;
    }
    for(int i=9;i>=0;i--)
    {
        while(bit[i]>0)
        {
            cout<<i;
            bit[i]--;
        }
    }
}