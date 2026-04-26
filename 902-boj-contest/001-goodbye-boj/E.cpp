#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define LEN 300001
typedef long long ll;
typedef long double lld;


using namespace std;

void divideAndConquer(int arr[], int l, int m, int r, long long *res)
{
     
    if(l>=m)
    {
        return;
    }
    divideAndConquer(arr, l, (l+m)/2, m, res);
    divideAndConquer(arr, m, (m+r)/2, r, res);
    int index=l;
    for(int i=m;i<r;i++)
    {
        while(arr[index]<=arr[i] && index!=m)
        {
            index++;
        }
        *res += m-index;
    }
    sort(arr+l,arr+r);
    return;
}

void program()
{
    int n;
    cin>>n;
    int arr[LEN];
    vector<int> graph[LEN];
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        graph[num].push_back(i);
        arr[i]=num;
    }
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        tot+=graph[i].size();
        if(i<tot)
        {
            cout<<-1<<"\n";
            return;
        }
    }
    
    long long res=0;
    divideAndConquer(arr,1,(n+2)/2,n+1,&res);
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