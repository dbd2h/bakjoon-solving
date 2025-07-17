#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int move=1;
    int x=1;
    if(n==1)
    {
        cout<<1;
    }
    else if(n==2)
    {
        if(m<=8)
        {
            while(x<m-1)
            {
                move++;
                x+=2;
            }
            cout<<move;
        }
        else
        {
            cout<<4;
        }
    }
    else
    {
        if(m<=4)
        {
            while(x<m)
            {
                move++;
                x+=1;
            }
            cout<<move;
        }
        else if(m<=6)
        {
            cout<<4;
        }
        else
        {
            x+=4;
            move+=2;
            while(x<m)
            {
                move++;
                x+=1;
            }
            cout<<move;
        }
    }
}