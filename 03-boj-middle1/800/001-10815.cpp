#include <iostream>

using namespace std;

int arr[500000]={0};

void quickSort(int l, int r)
{
    int st=l;
    int a=l+1;
    int b=r;
    if(a>b)
    {
        return;
    }
    int c=arr[(l+r)/2];
    arr[(l+r)/2]=arr[l];
    arr[l]=c;
    int isfinish=0;
    while(a<b)
    {
        while(arr[st]>arr[a])
        {
            if(a>=b)
            {
                isfinish=1;
                break;
            }
            a++;
        }
        while(arr[st]<arr[b])
        {
            if(a>=b)
            {
                isfinish=1;
                break;
            }
            b--;
        }
        if(isfinish) break;
        int c=arr[a];
        arr[a]=arr[b];
        arr[b]=c;
        a++;
        b--;
    }
    int div=r;
    for(;div>l;div--)
    {
        if(arr[div]<arr[st])
        {
            int c=arr[div];
            arr[div]=arr[st];
            arr[st]=c;
            quickSort(st, div-1);
            quickSort(div+1,r);
            return;
        }
    }
    quickSort(st+1, r);
    return;
}
int binarySearch(int l, int r, int num)
{
    if(l>r) return 0;
    if(arr[(l+r)/2]==num) return 1;
    else if(arr[(l+r)/2]<num) return binarySearch((l+r)/2+1, r, num);
    else if(arr[(l+r)/2]>num) return binarySearch(l, (l+r)/2-1, num);
    return 0;
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quickSort(0,n-1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int num;
        cin>>num;
        cout<<binarySearch(0,n-1,num)<<" ";
    }
    
}
