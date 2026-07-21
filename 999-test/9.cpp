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

void program()
{
    int n;
    string s;
    cin>>n>>s;
    // s[i] : i번째로 작은 원판이 놓인 peg (s[0]=가장 작은 원판, s[n-1]=가장 큰 원판)
    // 가장 큰 원판부터 훑으며 현재 구간의 from/to 를 갱신한다.
    // 시작 구간: 전체를 A -> B
    int from='A';
    int to='B';
    bool ok=true;
    for(int i=n-1;i>=0;i--)
    {
        int via='A'+'B'+'C'-from-to;          // 나머지 페그
        int diff=((to-'A')-(from-'A')+3)%3;   // 1=정방향(한 칸), 2=역방향(두 칸)
        int d=s[i];
        if(diff==1)                           // 정방향
        {
            if(d==from) to=via;               // 앞 절반: from->via
            else if(d==to) from=via;          // 뒤 절반: via->to
            else { ok=false; break; }         // via에 있으면 최적 수열에 없음
        }
        else                                  // 역방향
        {
            if(d==via)                        // 가운데 조각: to->from 으로 뒤집힘
            {
                int t=from; from=to; to=t;
            }
            // d==from 또는 d==to 이면 from/to 유지 (역방향 그대로)
        }
    }
    cout<<(ok?"YES":"NO")<<"\n";
}

int main()
{
    program();
}