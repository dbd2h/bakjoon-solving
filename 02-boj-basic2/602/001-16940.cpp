#include <iostream>
#include <vector>
#include <queue>

#define MAX_NODE 100001

using namespace std;

void quickSort(vector<int> &v, int l, int r)
{
    if(l>=r)
    {
        return;
    }
    int left=l+1;
    int right=r;
    while(left<right)
    {
        while(v[l]>v[left])
        {
            left+=1;
            if(left==right)
            {
                break;
            }
        }
        while(v[l]<v[right])
        {
            right-=1;
            if(left==right)
            {
                break;
            }
        }
        if(left>=right)
        {
            break;
        }
        int c=v[right];
        v[right]=v[left];
        v[left]=c;
        left++;
        right--;
    }
    right=r;
    while(v[right]>v[l])
    {
        right--;
    }
    int c=v[right];
    v[right]=v[l];
    v[l]=c;
    quickSort(v, l, right-1);
    quickSort(v, right+1, r);
}

int binarySearch(vector<int> v, int a, int l, int r)
{
    if(l>r)
    {
        return 0;
    }
    int num=(l+r)/2;
    if(v[num]==a)
    {
        return 1;
    }
    if(v[num]>a)
    {
        return binarySearch(v, a, l, num-1);
    }
    else if(v[num]<a)
    {
        return binarySearch(v, a, num+1, r);
    }
    return 1;
}

int main()
{
    vector<int> graph[MAX_NODE];
    int countGraph[MAX_NODE]={0};
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        countGraph[a]++;
        countGraph[b]++;
    }
    int bfsArr[MAX_NODE];
    int max=1;
    for(int i=1;i<=n;i++)
    {
        if(countGraph[max]<countGraph[i])
        {
            max=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>bfsArr[i];
        if(max==i)
        {
            continue;
        }
        quickSort(graph[i], 0,graph[i].size()-1);
    }

    int check[MAX_NODE]={0};
    int count=1;
    int start=2;
    check[1]=1;
    int isTrue=1;
    int isF=0;
    while(1)
    {
        if(bfsArr[1]!=1)
        {
            isTrue=0;
            break;
        }
        int countg=countGraph[bfsArr[count]];
        if(max==bfsArr[count])
        {
            start+=(countg-isF);
            count++;
            isF=1;
            continue;
        }
        for(int i=0;i<countg-isF;i++)
        {
            if(binarySearch(graph[bfsArr[count]], bfsArr[start+i], 0, countg-1))
            {
                continue;
            }
            else
            {
                isTrue=0;
                break;
            }
        }
        if(!isTrue)
        {
            break;
        }
        start+=(countg-isF);
        count++;
        isF=1;
        if(count>=n)
        {
            break;
        }
    }
    cout<<isTrue;
}