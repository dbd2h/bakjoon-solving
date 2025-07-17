#include <iostream>
#include <vector>

#define MAX_LEN 100'001

using namespace std;

void diameter(vector<pair<int,int>> tree[], int max[][2], int p, int now)
{
    for(int i=0;i<tree[now].size(); i++)
    {
        int c=tree[now][i].first;
        if(c==p)
        {
            continue;
        }
        diameter(tree, max, now, c);
    }
    int max1=0;
    int max2=0;
    for(int i=0;i<tree[now].size(); i++)
    {
        int c=tree[now][i].first;
        if(c==p)
        {
            continue;
        }
        int w=tree[now][i].second;
        if(max1<max[c][0]+w)
        {
            max2=max1;
            max1=max[c][0]+w;
        }
        else if(max2<max[c][0]+w)
        {
            max2=max[c][0]+w;
        }
    }
    max[now][0]=max1;
    max[now][1]=max2;
    return;
}

int main()
{
    vector<pair<int,int>> tree[MAX_LEN];
    int max[MAX_LEN][2]={0};
    int v;
    cin>>v;
    for(int i=0;i<v;i++)
    {
        int node;
        cin>>node;
        while(true)
        {
            int a,w;
            cin>>a;
            if(a==-1)
            {
                break;
            }
            cin>>w;
            tree[node].push_back({a,w});
        }
    }
    diameter(tree, max, 0, 1);

    int maxSum=0;
    for(int i=1;i<=v;i++)
    {
        if(maxSum<max[i][0]+max[i][1])
        {
            maxSum=max[i][0]+max[i][1];
        }
    }
    cout<<maxSum;
}