#include <iostream>

using namespace std;

void quickSort(int s[], int l, int r)
{
    if(l>r)
    {
        return;
    }
    int orir=r;
    int pivot=l++;
    int fr=r;
    while(true)
    {
        while(s[pivot]>s[l] && l<=r)
        {
            l++;
        }
        while(s[pivot]<s[r] && l<=r)
        {
            r--;
        }
        if(l>r)
        {
            break;
        }
        if(l<=r)
        {
            int c=s[l];
            s[l]=s[r];
            s[r]=c;
            l++;
            r--;
        }
    }
    while(s[pivot]<=s[fr] && pivot<fr)
    {
        fr--;
    }
    int c=s[pivot];
    s[pivot]=s[fr];
    s[fr]=c;
    quickSort(s, pivot, fr-1);
    quickSort(s, fr+1, orir);
}

int main()
{
    int n;
    int s[20]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    quickSort(s, 0, n-1);
    int sum=1;
    for(int i=0;i<n;i++)
    {
        if(sum<s[i])
        {
            break;
        }
        sum+=s[i];
    }
    cout<<sum;
}