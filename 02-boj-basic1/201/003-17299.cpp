#include <iostream>
#include <stack>

#define MILL 1'000'000

using namespace std;

int main()
{
    int count;
    cin>>count;
    int arr[count];
    int freArr[MILL];
    int finalArr[count];
    stack<int> stack;
    for(int i=0;i<MILL;i++)
    {
        freArr[i]=0;
    }
    int num;
    for(int i=0;i<count;i++)
    {
        cin>>num;
        freArr[num-1]++;
        arr[i]=num;
    }

    for(int i=0;i<count;i++)
    {
        if(!stack.empty())
        {
            while(freArr[arr[stack.top()]-1]<freArr[arr[i]-1])
            {
                finalArr[stack.top()]=arr[i];
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
        finalArr[stack.top()]=-1;
        stack.pop();
    }
    for(int i=0;i<count;i++)
    {
        cout<<finalArr[i];
        if(i+1!=count)
        {
            cout<<' ';
        }
    }
    cout<<"\n";
}