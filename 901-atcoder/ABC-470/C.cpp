#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 500001

using namespace std;
int arr[LEN]={0};
map<int,int> bit;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    int res=0;
    int mi=0;
    for(int i=0;i<q;i++)
    {
        int sign;
        cin>>sign;
        if(sign==1)
        {
            int idx;
            cin>>idx;
            if(arr[idx]-mi<=0)
            {
                arr[idx]=mi+1;
                bit[1]++;
                res^=1;
            }
            else
            {
                res^=(arr[idx]-mi);
                bit[arr[idx]-mi]--;
                if(bit[arr[idx]-mi]==0) bit.erase(arr[idx]-mi);
                arr[idx]++;
                res^=(arr[idx]-mi);
                bit[arr[idx]-mi]++;
            }
        }
        else
        {
            vector<pair<int,int>> v;
            for(auto& p : bit)
            {
                int key=p.first;
                int num=p.second;
                v.push_back({key,num});
                if(num%2==1)
                {
                    res^=key;
                    res^=(key-1);
                }
            }
            for(auto& p : v)
            {
                int key=p.first;
                int num=p.second;
                if(key!=1) bit[key-1]=num;
                bit.erase(key);
            }
            mi++;
        }
        cout<<res<<"\n";
    }
    
}