#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int num)
{
    if(num<0) num=-num;
    return num;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int idx=n-1;
    int res=2e9+1;
    int resI=-1;
    int resJ=-1;

    for(int i=0;i<n;i++)
    {
        int cur=v[i];
        while(idx>i)
        {
            int sumV=cur+v[idx];
            if(abs(res)>abs(sumV))
            {
                res=sumV;
                resI=i;
                resJ=idx;
            }
            if(cur+v[idx]<0)
            {
                if(idx!=n-1) idx++;
                break;
            }
            idx--;
        }
        if(idx==i) break;
    }
    cout<<v[resI]<<" "<<v[resJ];
}