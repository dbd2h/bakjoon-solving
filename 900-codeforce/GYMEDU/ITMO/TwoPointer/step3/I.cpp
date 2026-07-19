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
#define LEN 100001

using namespace std;

struct STACK
{
    vector<int> v;
    vector<vector<int>> dp;
    STACK()
    {
        v.clear();
        dp.clear();
        dp.push_back(vector<int>(1001,0));
        dp[0][0]=1;
    }
    void Push(int num, int s)
    {
        vector<int> curV=dp.back();
        for(int i=s;i>=num;i--)
        {
            if(curV[i-num]==0) continue;
            curV[i]=1;
        }
        v.push_back(num);
        dp.push_back(std::move(curV));
    }
    bool Empty()
    {
        return v.empty();
    }
    void Pop()
    {
        v.pop_back();
        dp.pop_back();
    }
    int Top()
    {
        return v.back();
    }
    bool good(STACK &st, int s)
    {
        for(int i=0;i<=s;i++)
        {
            if(dp.back()[i]==1 && st.dp.back()[s-i]==1) return true;
        }
        return false;
    }
};

int main()
{
    int n,s;
    cin>>n>>s;
    int arr[LEN];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int l=0;
    int r=0;
    int res=-1;
    STACK fst,bst;
    while(r<=n)
    {
        if(fst.good(bst,s))
        {
            if(res==-1 || res>(r-l)) res=r-l;
            l++;
            if(fst.Empty())
            {
                while(!bst.Empty())
                {
                    fst.Push(bst.Top(),s);
                    bst.Pop();
                }
            }
            fst.Pop();
        }
        else
        {
            r++;
            if(r>n) break;
            bst.Push(arr[r],s);
        }
    }   
    cout<<res;
}