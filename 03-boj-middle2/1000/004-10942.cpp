#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[2001]={0};
    bool palindrome[2001][2001]={false};
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        palindrome[i][i]=true;
        if(i>1)
        {
            if(arr[i-1]==arr[i])palindrome[i-1][i]=true;
        }
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(palindrome[j+1][i-1] && arr[i]==arr[j])palindrome[j][i]=true;
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int s,e;
        cin>>s>>e;
        cout<<palindrome[s][e]<<"\n";
    }
}