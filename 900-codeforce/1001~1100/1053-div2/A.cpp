#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void program()
{
    int n,m;
    cin>>n>>m;
    int arr[200];
    int end=0;
    int isF=-1;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    bool isC=true;
    for(int i=1;i<m;i++)
    {
        if(arr[i-1]+1==arr[i]) continue;
        isC=false;
        break;
    }
    if(!isC)
    {
        cout<<1<<"\n";
        return;
    }
    cout<<n-arr[m-1]+1<<"\n";
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