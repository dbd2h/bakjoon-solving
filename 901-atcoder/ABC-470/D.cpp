#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 500001

using namespace std;
int arr[LEN];
int posArr[LEN];

int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        posArr[arr[i]]=i;
    }
    bool isSwap=false;
    for(int i=0;i<q;i++)
    {
        int sign;
        cin>>sign;
        if(sign==1)
        {
            int x,y;
            cin>>x>>y;
            if(isSwap)
            {
                int n1=posArr[x];
                int n2=posArr[y];
                int c=posArr[x];
                posArr[x]=posArr[y];
                posArr[y]=c;

                c=arr[n1];
                arr[n1]=arr[n2];
                arr[n2]=c;
            }
            else
            {
                int n1=arr[x];
                int n2=arr[y];
                int c=arr[x];
                arr[x]=arr[y];
                arr[y]=c;

                c=posArr[n1];
                posArr[n1]=posArr[n2];
                posArr[n2]=c;
            }
        }
        else
        {
            isSwap=!isSwap;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(isSwap) cout<<posArr[i]<<" ";
        else cout<<arr[i]<<" ";
    }
}