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

int main()
{
    string s;
    cin>>s;
    int len=s.size();
    if(s[0]== s[len-1]) len++;
    if(len%2==1) cout<<"First";
    else cout<<"Second";
}

// 1. 신호: 우선 두명이 번갈아서 진행하고, 최선의 수가 존재 -> 게임 이론
// 2. 도구: 게임 이론
// 3. 막힌 지점: 그리디를 써야 한다는 건 알았지만, 하나하나 최선의 수를 제거해 가야 하는 줄 알았음. 여러가지 케이스로 시험해봤는데,
// abababab 이런 경우가 아니고선 최선의 방법의 경우 맨 앞,뒤가 다를땐 2개가 남고, 같을 땐 3개가 남음. 즉 짝수, 홀수로 판단할 수 있다고 생각