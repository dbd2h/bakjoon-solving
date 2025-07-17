#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int test=0;test<t;test++)
    {
        int n,q;
        cin>>n>>q;
        int arr[200000]={0};
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        string s="";
        cin>>s;
        for(int i=0;i<q;i++)
        {
            int num;
            cin>>num;
            if(s[num]=='R') s[num]='L';
            else s[num]='R';
        }
    }
}