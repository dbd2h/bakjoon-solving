#include <iostream>
#include <vector>

using namespace std;

void camp(int *arr, vector <int> graph[2000], int n, int count, int *finish);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<int> graph[2000];
    vector <int> v;
    v.push_back(1);
    for(int i=0;i<m;i++)
    {
        int from, to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int arr[5];
    int finish=0;
    camp(arr, graph, n, 0, &finish);
    cout<<finish;
}

void camp(int *arr, vector <int> graph[2000], int n, int count, int *finish)
{
    if(*finish==1)
    {
        return;
    }
    if(count==5)
    {
        *finish=1;
        return;
    }
    if(count==0)
    {
        for(int i=0;i<n;i++)
        {
            if(*finish==1)
            {
                return;
            }
            arr[count]=i;
            camp(arr, graph, n, count+1, finish);
        }
    }
    int last=arr[count-1];
    int len=graph[last].size();
    for(int i=0;i<len;i++)
    {
        if(*finish==1)
        {
            return;
        }
        int value=graph[last][i];
        int skip=0;
        for(int j=0;j<count;j++)
        {
            if(value==arr[j])
            {
                skip=1;
                break;
            }
        }
        if(skip==1)
        {
            continue;
        }
        arr[count]=value;
        camp(arr, graph, n, count+1, finish);
    }
}