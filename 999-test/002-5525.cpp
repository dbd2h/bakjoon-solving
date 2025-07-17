#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<m;i++)
    {
        int IOICount=0;
        if(s[i]=='I')
        {
            while(i+2<m)
            {
                if(s[i+1]=='O' && s[i+2]=='I')
                {
                    IOICount++;
                    i+=2;
                }
                else
                    break;
            }
            if(IOICount>=n)
            {
                count+=IOICount-n+1;
            }
        }
    }
    cout<<count;
}