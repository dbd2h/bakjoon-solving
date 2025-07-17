#include <iostream>

#define MAX_LEN 10'001

using namespace std;

struct Node
{
    int left;
    int right;
}Node;

void inOrder(struct Node n[MAX_LEN], int countArr[][2], int *count, int level, int now)
{
    if(now==-1)
    {
        return;
    }
    int l,r;
    l=n[now].left;
    r=n[now].right;
    inOrder(n, countArr, count, level+1, l);
    (*count)++;
    if(countArr[level][0]==0)
    {
        countArr[level][0] = *count;
    }
    countArr[level][1] = *count;
    inOrder(n,countArr, count, level+1, r);
    return;
}

int main()
{
    struct Node node[MAX_LEN];
    int countArr[MAX_LEN][2]={0};
    int hasP[MAX_LEN]={0};
    int n;
    int count=0;
    int root;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int p,l,r;
        cin>>p>>l>>r;
        node[p].left=l;
        node[p].right=r;
        if(l!=-1)
        {
            hasP[l]=1;
        }
        if(r!=-1)
        {
            hasP[r]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!hasP[i])
        {
            root=i;
            break;
        }
    }
    inOrder(node, countArr, &count, 1, root);
    int max=0;
    int maxWid=0;
    for(int i=1;i<MAX_LEN;i++)
    {
        if(countArr[i][0]==0 && countArr[i][1]==0)
        {
            break;
        }
        if(countArr[i][1]-countArr[i][0]+1>maxWid)
        {
            maxWid=countArr[i][1]-countArr[i][0]+1;
            max=i;
        }
    }
    cout<<max<<" "<<maxWid;
}