#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 200001

using namespace std;

void program()
{
    int n;
    cin>>n;
    int oddArr[LEN];
    int evenArr[LEN];
    int oddLen=0;
    int evenLen=0;
    int oddMax=0;
    int oddMin=1e9;
    int evenMax=0;
    int evenMin=1e9;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(num%2==1)
        {
            oddArr[oddLen]=num;
            oddLen++;
            oddMax=max(oddMax,num);
            oddMin=min(oddMin,num);
        }
        else 
        {
            evenArr[evenLen]=num;
            evenLen++;
            evenMax=max(evenMax,num);
            evenMin=min(evenMin,num);
        }
    }
    if(oddMax==0)
    {
        bool isF=false;
        for(int i=0;i<evenLen-1;i++)
        {
            if(evenArr[i]<=evenArr[i+1]) continue;
            isF=true;
            break;
        }
        if(isF) cout<<"NO\n";
        else cout<<"YES\n";
        return;
    }
    if(evenMax==0)
    {
        bool isF=false;
        for(int i=0;i<oddLen-1;i++)
        {
            if(oddArr[i]<=oddArr[i+1]) continue;
            isF=true;
            break;
        }
        if(isF) cout<<"NO\n";
        else cout<<"YES\n";
        return;
    }
    bool isMax=false;
    for(int i=0;i<oddLen;i++)
    {
        if(oddArr[i]>evenMax)
        {
            isMax=true;
        }
        if(isMax && oddArr[i]<evenMin)
        {
            cout<<"NO\n";
            return;
        }
    }
    isMax=false;
    for(int i=0;i<evenLen;i++)
    {
        if(evenArr[i]>oddMax)
        {
            isMax=true;
        }
        if(isMax && evenArr[i]<oddMin)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}