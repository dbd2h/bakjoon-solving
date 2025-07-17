#include<iostream>

using namespace std;

int sub(int n1, int n2);
int isLeftBig(int n1, int n2);

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long m,n,x,y, tot=1;
        cin>>m>>n>>x>>y;
        int x1=1,y1=1;
        int dif=sub(x,y);
        int xyBig=isLeftBig(x,y);
        while(tot<=m*n+1)
        {
            if(isLeftBig(x1,y1)==xyBig&&dif==sub(x1,y1))
            {
                while(x!=x1)
                {
                    tot++;
                    x1++;
                    y1++;
                }
                break;
            }
            if(m-x1+1>n-y1+1)
            {
                tot+=(n-y1+1);
                x1+=(n-y1+1);
                y1=1;
            }
            else if(m-x1+1<n-y1+1)
            {
                y1+=(m-x1+1);
                tot+=(m-x1+1);
                x1=1;
            }
            else
            {
                tot+=(m-x1+1);
                x1=1;
                y1=1;
            }
        }
        if(tot>m*n+1)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<tot<<"\n";
        }
    }
}

int sub(int n1, int n2)
{
    if(n1>n2)
    {
        return n1-n2;
    }
    else
    {
        return n2-n1;
    }
}

int isLeftBig(int n1, int n2)
{
    if(n1>n2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}