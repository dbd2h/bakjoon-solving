#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int count;
    cin>>count;
    int num;
    int arr[count];
    int rightBig[count];
    stack<int> stack;

    for(int i=0;i<count;i++)
    {
        cin>>num;
        arr[i]=num;
        if(!stack.empty())
        {
            while(arr[stack.top()]<arr[i])
            {
                rightBig[stack.top()]=arr[i];
                stack.pop();
                if(stack.empty())
                {
                    break;
                }
            }
        }
        stack.push(i);
    }
    while(!stack.empty())
    {
        rightBig[stack.top()]= -1;
        stack.pop();
    }
    for(int i=0;i<count;i++)
    {
        cout<<rightBig[i];
        if(i+1!=count)
        {
            cout<<' ';
        }
    }
    cout<<"\n";
}