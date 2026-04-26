#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int sum(int idx) const {
        int ret = 0;
        for (; idx > 0; idx -= idx & -idx) {
            ret += bit[idx];
        }
        return ret;
    }

    int rangeSum(int l, int r) const {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<int>> byA(N + 1);

        for (int i = 1; i <= N; i++) {
            int a;
            cin >> a;
            byA[a].push_back(i);
        }

        Fenwick fw(N);
        for (int i = 1; i <= N; i++) {
            fw.add(i, 1);
        }

        priority_queue<int> pq;
        long long ans = 0;
        bool ok = true;

        for (int k = N; k >= 1; k--) {
            for (int idx : byA[k]) {
                pq.push(idx);
            }

            if (pq.empty()) {
                ok = false;
                break;
            }

            int idx = pq.top();
            pq.pop();

            // 아직 남아 있는 사람 중 idx 오른쪽에 있는 사람 수
            ans += fw.rangeSum(idx + 1, N);

            // idx를 최종 위치 k에 배치했으므로 제거
            fw.add(idx, -1);
        }

        cout << (ok ? ans : -1) << '\n';
    }

    return 0;
}