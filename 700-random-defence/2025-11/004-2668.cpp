#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[101];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    bool res[101]={0};
    for(int i=1;i<=n;i++)
    {
        int idx=i;
        int num=arr[idx];
        int tot=1;
        bool check[101]={0};
        vector<int> v;
        bool isF=0;
        while(true)
        {
            if(check[num]==1)
            {
                isF=1;
                break;
            }
            check[num]=1;
            v.push_back(num);
            if(num==i) break;
            idx=num;
            num=arr[num];
        }
        if(isF==0)
        {
            for(auto &i : v)
            {
                res[i]=1;
            }
        }
    }
    vector<int> outputV;
    int resN=0;
    for(int i=1;i<=n;i++)
    {
        if(res[i]==0) continue;
        resN++;
        outputV.push_back(i);
    }
    cout<<resN<<"\n";
    for(auto &i : outputV) cout<<i<<"\n";
}