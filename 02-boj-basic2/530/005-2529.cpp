#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    char ineq[n];
    int maxArr[n+1];
    int minArr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>ineq[i];
    }
    int right=0;
    int left=0;
    //Maximum
    for(int i=0;i<=n;i++)
    {
        int r=right;
        if(i==n)
        {
            while(right>=0)
            {
                maxArr[i-right]=9-i+r-right;
                right--;
            }
        }
        else if(ineq[i]=='>')
        {
            while(right>=0)
            {
                maxArr[i-right]=9-i+r-right;
                right--;
            }
        }
        right++;

        int l=left;
        if(i==n)
        {
            while(left>=0)
            {
                minArr[i-left]=i-l+left;
                left--;
            }
        }
        else if(ineq[i]=='<')
        {
            while(left>=0)
            {
                minArr[i-left]=i-l+left;
                left--;
            }
        }
        left++;
    }
    for(int i=0;i<n+1;i++)
    {
        cout<<maxArr[i];
    }
    cout<<"\n";
    for(int i=0;i<n+1;i++)
    {
        cout<<minArr[i];
    }
}