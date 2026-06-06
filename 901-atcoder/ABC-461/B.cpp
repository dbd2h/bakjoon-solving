#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main()
{
    int a[101];
    int b[101];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    bool check[101];
    for(int i=1;i<=n;i++) check[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(check[i]) continue;
        int cur=i;
        int next=a[i];
        bool isF=false;
        while(true)
        {
            if(check[next]) break;
            if(b[next]==cur)
            {
                check[next]=1;
                cur=next;
                next=a[next];
            }
            else
            {
                isF=true;
                break;
            }
            
        }
        if(isF)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}