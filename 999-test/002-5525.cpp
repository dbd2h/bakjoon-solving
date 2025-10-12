#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int a = count(s.begin(), s.end(), 'a');
    int b = n - a;
    int need = a - b;
    map<int, int> mp;
    mp[0] = -1;
    int cur = 0;
    int ans = n;
    for (int i = 0; i < n; i++) {
        cur += s[i] == 'a';
        cur -= s[i] == 'b';
        if (mp.count(cur - need)) {
            ans = min(ans, i - mp[cur - need]);
        }
        mp[cur] = i;
    }
    if (ans == n) ans = -1;
    if (need == 0) ans = 0;
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}