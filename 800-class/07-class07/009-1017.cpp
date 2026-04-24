#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[25];
int rmatch[25];

bool dfs(bool check[25], int cur)
{
    for(auto &next : graph[cur])
    {
        if(check[next]) continue;
        int w=rmatch[next];
        check[next]=1;
        if(w==-1 || dfs(check,w))
        {
            rmatch[next]=cur;
            return true;
        }
    }
    return false;
}

int main()
{
    int primeArr[2001]={0};
    primeArr[1]=1;
    for(int i=2;i<=2000;i++)
    {
        if(primeArr[i]) continue;
        if(i*i>2000) break;
        for(int j=i+i;j<2000;j+=i)
        {
            primeArr[j]=1;
        }
    }
    int n;
    cin>>n;
    int lArr[25];
    int rArr[25];
    bool isOdd=1;
    int lIdx=0;
    int rIdx=0;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(i==0)
        {
            lArr[lIdx]=num;
            lIdx++;
            if(num%2==0) isOdd=0;
            continue;
        }
        if(num%2==isOdd)
        {
            lArr[lIdx]=num;
            lIdx++;
        }
        else
        {
            rArr[rIdx]=num;
            rIdx++;
        }
    }
    if(lIdx!=rIdx)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            int cur=lArr[i]+rArr[j];
            if(primeArr[cur]) continue;
            graph[i].push_back(j);
        }
    }
    vector<int> resV;
    for(auto &i : graph[0])
    {
        for(int i=0;i<n/2;i++) rmatch[i]=-1;
        rmatch[i]=0;
        bool isContinue=true;
        for(int j=1;j<n/2;j++)
        {
            bool check[25]={0};
            check[i]=1;
            isContinue=dfs(check,j);
            if(!isContinue) break;
        }
        if(isContinue)
        {
            resV.push_back(rArr[i]);
        }
    }
    sort(resV.begin(),resV.end());
    int len=resV.size();
    if(len==0) cout<<-1;
    for(int i=0;i<len;i++)
    {
        cout<<resV[i]<<" ";
    }
}