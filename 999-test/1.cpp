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
    string s;
    cin>>s;
    int x=0; // 4의 개수 + 1,3의 개수
    int y=0; // 4의 개수 + 2의 개수 or 지금까지 최소로 지우는 수
    for(int i=0;i<s.size();i++)
    {
        int cur=s[i]-'0';
        if(cur==4)
        {
            x++;
            y++;
        }
        else if(cur%2==1)
        {
            y=min(x,y); // 이때 최소로 지우는 수 기록
            x++;
        }
        else y++; // 이때는 최소로 지우는 수, 2의 개수
    }
    cout<<min(x,y)<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}