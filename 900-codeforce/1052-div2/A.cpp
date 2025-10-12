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
    int arr[101]={0};
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        arr[num]++;
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int sumV=0;
        for(int j=1;j<=n;j++)
        {
            if(!arr[j]) continue;
            if(arr[j]>=i) sumV+=i;
        }
        if(res<sumV) res=sumV;
    }
    cout<<res<<"\n";

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