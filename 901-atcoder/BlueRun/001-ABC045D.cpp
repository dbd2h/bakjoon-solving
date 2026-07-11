#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

using namespace std;

map<pair<int,int>,bool> inputM;
map<pair<int,int>,bool> centerM;

int main()
{
    ll h,w,n;
    cin>>h>>w>>n;
    vector<pair<int,int>> v;
    ll res[10]={0};
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        inputM[{a,b}]=1;
        v.push_back({a,b});
    }
    for(int i=0;i<n;i++)
    {
        int a=v[i].first;
        int b=v[i].second;
        for(int sx=a-2;sx<=a;sx++)
        {
            for(int sy=b-2;sy<=b;sy++)
            {
                if(sx<=0 || sy<=0 || sx+2>h || sy+2>w) continue;
                if(centerM[{sx+1,sy+1}]) continue;
                int sumV=0;
                for(int x=sx;x<=sx+2;x++)
                {
                    for(int y=sy;y<=sy+2;y++)
                    {
                        if(inputM[{x,y}]) sumV++;
                    }
                }
                res[sumV]++;
                centerM[{sx+1,sy+1}]=1;
            }
        }
    }
    ll sumV=0;
    for(int i=1;i<=9;i++) sumV+=res[i];
    cout<<(h-2)*(w-2)-sumV<<"\n";
    for(int i=1;i<=9;i++) cout<<res[i]<<"\n";
}

// time: 29M 10S
// 