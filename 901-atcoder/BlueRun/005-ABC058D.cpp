#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 100001
#define MOD (ll)(1e9+7)

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    ll x[LEN];
    ll y[LEN];
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<m;i++) cin>>y[i];
    ll xSum=0;
    ll xMul=n-1;
    for(int i=0;i<n;i++)
    {
        xSum+=x[i]*xMul;
        xSum%=MOD;
        xSum=(xSum+MOD)%MOD;
        xMul-=2;
    }
    ll ySum=0;
    ll yMul=m-1;
    for(int i=0;i<m;i++)
    {
        ySum+=y[i]*yMul;
        ySum%=MOD;
        ySum=(ySum+MOD)%MOD;
        yMul-=2;
    }
    xSum*=ySum;
    xSum%=MOD;
    cout<<xSum;
}

// time: 15M 28S Solve
// 1. 신호: 각 직사각형의 면적을 구하려면 O(n*n*m*m)이 필요함. 즉 단순히는 못 구하고, y 좌표 두개가 고정되었을 때 식을 구해봄. 이때 (y1-y2)에 곱해주는 x좌표들이 y값이 달라져도 똑같다는 걸 알고, 분배법칙 적용
// 2. 도구: 분배법칙을 통해 나온 식을 그대로 구현해주면 됨.
// 3. 막힌 지점: 처음에 그림을 그려서 이를 해석하려 했는데, 그건 수학할 때나 하는 거고, 컴퓨터 할 때는 식세우기