#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<1<<"\n";
            continue;
        }
        bool check[20001]={0};
        queue<string> q;
        q.push("1");
        check[1]=1;
        bool isF=false;
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            int m=0;
            for(int i=0;i<s.size();i++)
            {
                m*=10;
                if(s[i]=='1') m+=1;
                m%=n;
            }
            int a=(m*10+1)%n;
            int b=(m*10)%n;
            if(a==0)
            {
                cout<<s<<"1\n";
                isF=true;
                break;
            }
            if(b==0)
            {
                cout<<s<<"0\n";
                isF=true;
                break;
            }
            if(check[a]==0)
            {
                check[a]=1;
                q.push(s+'1');
            }
            if(check[b]==0)
            {
                check[b]=1;
                q.push(s+'0');
            }
        }
        if(!isF)
        {
            cout<<"BRAK\n";
        }
    }
}