#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<int> stack;
    string pm;
    int count;
    cin>>count;
    int num;
    cin>>num;
    for(int i=1;i<=count;i++)
    {
        stack.push(i);
        pm+='+';
        while(stack.top()==num)
        {
            pm+='-';
            stack.pop();
            if(pm.length()==count*2)
            {
                break;
            }
            cin>>num;
            if(stack.empty())
            {
                break;
            }
        }
    }
    if(stack.empty())
    {   
        int len=pm.length();
        for(int i=0;i<len;i++)
        {
            cout<<pm[i]<<"\n";
        }
    }
    else
    {
        cout<<"NO"<<"\n";
    }
}