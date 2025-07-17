#include <iostream>
#include <string>

using namespace std;

struct stack{
    int arr[10000];
    int last;

    void init()
    {
        last=-1;
    }

    void push(int x)
    {
        last++;
        arr[last]=x;
    }
    
    int pop()
    {
        if(last==-1)
        {
            return -1;
        }
        last--;
        return arr[last+1];
    }

    int size()
    {
        return last+1;
    }

    int empty()
    {
        if(last==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int top()
    {
        if(last==-1)
        {
            return -1;
        }
        else
        {
            return arr[last];
        }
    }
};

int main()
{
    stack s1;
    s1.init();
    int total;
    cin>>total;
    string cmd;
    int num;
    for(int i=0;i<total;i++)
    {
        cin>>cmd;
        if(cmd=="push")
        {
            cin>>num;
            s1.push(num);
        }
        else if(cmd=="pop")
        {
            cout<<s1.pop()<<"\n";
        }
        else if(cmd=="size")
        {
            cout<<s1.size()<<"\n";
        }
        else if(cmd=="empty")
        {
            cout<<s1.empty()<<"\n";
        }
        else if(cmd=="top")
        {
            cout<<s1.top()<<"\n";
        }
    }
}