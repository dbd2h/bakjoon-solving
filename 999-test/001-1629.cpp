#include <iostream>
using namespace std;

#define LEN 300005          // N, Q 제약에 맞춰 조정 (LEN >= max(N+1, Q+2))

int N, Q;
long long bit[2][LEN];       // atcoder FenwickTree f[0], f[1] 대응
int last[2][LEN];            // last[t][x] = (t, x)가 마지막으로 등장한 쿼리 번호

// atcoder add(p, x): 0-index 점 갱신 -> 내부 1-index BIT (p+1 시프트)
void update(int t, int p, int v)
{
	for (p++; p < LEN; p += p & -p)
		bit[t][p] += v;
}

// query(t, r) = atcoder f[t].sum(0, r) = [0, r) 구간 합
long long query(int t, int r)
{
	long long ret = 0;
	for (; r > 0; r -= r & -r)
		ret += bit[t][r];
	return ret;
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> Q;

	for (int x = 1; x <= N; x++)
		last[0][x] = -1;     // last[1]은 전역 0 초기화 그대로 (= 0)

	long long b = 0;
	for (int i = 1; i <= Q; i++)
	{
		int t, x;
		cin >> t >> x;
		t--;

		if (last[t][x] == -1)
		{
			b += N;
		}
		else
		{
			long long kind = query(1 - t, i) - query(1 - t, last[t][x]);
			b += (t == 0 ? kind : -kind);
			update(t, last[t][x], -1);
		}
		update(t, i, 1);
		last[t][x] = i;
        cout << b << "\n";
	}

	
	return 0;
}