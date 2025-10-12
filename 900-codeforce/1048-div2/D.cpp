#include <bits/stdc++.h>

using namespace std;

void program()
{
    int n,q;
    cin>>n>>q;
    int p[500000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int res[500000]={0};
    int a=0;
    int b=-1;
    int c=-1;
    int A=-1;
    int idx=-1;
    for(int i=1;i<n;i++)
    {
        if(b==-1 && A==-1)
        {
            if(p[i]>p[a])
            {
                a=i;
            }
            else if(p[i]<p[a])
            {
                b=i;
            }
        }
        else if(A==-1)
        {
            if(p[i]>p[a])
            {
                A=i;
            }
            else if(p[i]<p[a] && p[i]>p[b])
            {
                b=i;
            }
            else if(p[i]<p[b])
            {
                c=i;
                while(idx<n)
                {
                    idx++;
                    res[idx]=c-1;
                    if(idx==a) break;
                }
                a=b;
                b=c;
                c=-1;
            }
        }
        else
        {
            if(p[i]<p[b])
            {
                c=i;
                while(idx<n)
                {
                    idx++;
                    res[idx]=c-1;
                    if(idx==a) break;
                }
                a=A;
                b=c;
                c=-1;
                A=-1;
            }
            else if(p[i]>p[b] && p[i]<p[A])
            {
                a=A;
                b=i;
                A=-1;
            }
            else if(p[i]>p[A])
            {
                A=i;
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        if(res[a-1]==0 || res[a-1]>=b-1) cout<<"YES\n";
        else cout<<"NO\n";
    }
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