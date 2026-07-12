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

// time: 29M 10S Solve
// 1. 신호: h,w는 1e9로 큰 수지만 검은색의 개수 n은 1e5까지만임. 즉 저 검은색들만 다루면 된다고 판단
// 2. 도구: 즉 모든 검은색에서 탐색하면 된다고 판단. 따라서 한 검은색을 찾고, 현재 검은색이 포함되는 3x3 네모들을 모두 조사.
// 3. 막힌 지점: 다만 검은색에서 주변에 검은색이 몇 개 있는지 파악하기 위해선 이를 배열로 담아야 하는데, 크기가 너무 큼
//    -> map을 활용하여 검은색이면 1, 아니면 0 을 나타낼 수 있음.