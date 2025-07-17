#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000]={0};

int n;

void quickSort(int l, int r)
{
    if(l>=r) return;
    int c=arr[l];
    arr[l]=arr[(l+r)/2];
    arr[(l+r)/2]=c;
    int pivot=l;
    int a=l+1;
    int b=r;
    while(a<=b)
    {
        while(arr[pivot]>=arr[a] && a<b)
        {
            a++;
        }
        while(arr[pivot]<=arr[b] && b>l)
        {
            b--;
        }
        if(a>=b)
        {
            int c=arr[pivot];
            arr[pivot]=arr[b];
            arr[b]=c;
            break;
        }
        int c=arr[a];
        arr[a]=arr[b];
        arr[b]=c;
    }
    quickSort(l, b-1);
    quickSort(b+1,r);
}

int binarySearchL(int l, int r, int num)
{
    if(l>r) return -1;
    if(arr[(l+r)/2]>num)    return binarySearchL(l, (l+r)/2-1, num);
    else if(arr[(l+r)/2]<num) return binarySearchL((l+r)/2+1, r, num);
    else
    {
        if((l+r)/2==0 || arr[(l+r)/2-1]!=num) return (l+r)/2;
        else return binarySearchL(l, (l+r)/2-1, num);
    }
}
int binarySearchR(int l, int r, int num)
{
    if(l>r) return -1;
    if(arr[(l+r)/2]>num)    return binarySearchR(l, (l+r)/2-1, num);
    else if(arr[(l+r)/2]<num) return binarySearchR((l+r)/2+1, r, num);
    else
    {
        if((l+r)/2==n-1 || arr[(l+r)/2+1]!=num) return (l+r)/2;
        else return binarySearchR((l+r)/2+1,r, num);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n;
    int bit[2000001]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++)
    {
        int num;
        cin>>num;
        int searchL, searchR;
        searchL=binarySearchL(0, n-1, num);
        searchR=binarySearchR(0,n-1,num);
        if(searchL==-1) cout<<0<<" ";
        else cout<<searchR-searchL+1<<" ";
    }

}


