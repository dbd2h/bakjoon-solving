#include <iostream>
#include <string>

struct queue
{
    int arr[10000];
    int f;
    int b;

    void init()
    {
        f=0;
        b=-1;
    }

    void push(int x)
    {
        b++;
        arr[b]=x;
    }

    int pop()
    {
        if(f>b)
        {
            return -1;
        }
        f++;
        return arr[f-1];
    }

    int size()
    {
        return b-f+1;
    }

    int empty()
    {
        if(f>b)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int front()
    {
        if(f>b)
        {
            return -1;
        }
        return arr[f];
    }

    int back()
    {
        if(f>b)
        {
            return -1;
        }
        return arr[b];
    }
};

using namespace std;

int main()
{
    queue q;
    q.init();
    int count;
    cin>>count;
    string s;
    int num;

    for(int i=0;i<count;i++)
    {
        cin>>s;
        if(s=="push")
        {
            cin>>num;
            q.push(num);
        }
        else if(s=="pop")
        {
            cout<<q.pop()<<"\n";
        }
        else if(s=="size")
        {
            cout<<q.size()<<"\n";
        }
        else if(s=="empty")
        {
            cout<<q.empty()<<"\n";
        }
        else if(s=="front")
        {
            cout<<q.front()<<"\n";
        }
        else if(s=="back")
        {
            cout<<q.back()<<"\n";
        }
    }
}