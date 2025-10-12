#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void program()
{
    long long k,x;
    cin>>k>>x;
    int bit[61]={0};
    int c=0;
    while(x)
    {
        bit[c]=(x%2);
        x/=2;
        c++;
    }
    vector<int> resV;
    int idx=0;
    bool isStart=0;
    while(true)
    {
        if(idx==k+1) break;
        if(bit[idx]==0 && !isStart)
        {
            idx++;
            continue;
        }
        if(bit[idx]==1 && !isStart)
        {
            isStart=true;
            idx++;
            continue;
        }
        if(bit[idx])
        {
            resV.push_back(2);
        }
        else resV.push_back(1);
        idx++;
    }
    cout<<resV.size()<<"\n";
    for(int i=0;i<resV.size();i++)
    {
        cout<<resV[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}