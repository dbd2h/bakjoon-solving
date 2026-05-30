#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void program()
{
    int n;
    cin>>n;
    int arr[200001];
    string s;
    cin>>s;
    int l=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            if(i==n-1)
            {
                if(i-l==0 && n!=1)
                {
                    cout<<"NO\n";
                    return;
                }
                int startN=i+1;
                while(l<=i)
                {
                    arr[l]=startN;
                    startN--;
                    l++;
                }
            }
            continue;
        }
        if(i-l==1)
        {
            cout<<"NO\n";
            return;
        }
        int startN=i;
        while(l<i)
        {
            arr[l]=startN;
            startN--;
            l++;
        }
        arr[i]=i+1;
        l=i+1;
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
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