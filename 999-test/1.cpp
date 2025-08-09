#include <stdio.h>
#include <string.h>
#define MOD 100000

int cache[200][200];
char s[201], ovf;

int dp(int l, int r) {
	int i;
	long long res = 0, t;
	if (l > r) return 1;
	if (cache[l][r] != -1) return cache[l][r];
	
	if (s[l] < 0 || (1 <= s[r] && s[r] <= 3)) return 0;
	for (i = l + 1 ; i <= r ; i += 2) {
		if (s[l] == 5 || s[i] == 5) {
			if (s[l] == 5 && s[i] == 5) {
				if (t = dp(i + 1, r)) {
					res += (long long)3 * dp(l + 1, i - 1) * t;
					if (res >= MOD) ovf = 1, res %= MOD;
				}
			}
			else if ((s[l] == 5 && s[i] < 0) || (s[l] > 0 && s[i] == 5)) {
				if (t = dp(i + 1, r)) {
					res += (long long)dp(l + 1, i - 1) * t;
					if (res >= MOD) ovf = 1, res %= MOD;
				}
			}
		}
		else if (s[i] == -s[l]) {
			if (t = dp(i + 1, r)) {
				res += (long long)dp(l + 1, i - 1) * t;
				if (res >= MOD) ovf = 1, res %= MOD;
			}
		}
	}

	return cache[l][r] = (int)res;
}

int main() {
	int n, r;

	scanf("%d%s", &n, s);
	
	if (n & 1) {
		printf("0");
		return 0;
	}
	memset(cache, 0xff, sizeof(cache));
	
	for (n = 0 ; s[n] ; n++) {
		switch (s[n]) {
			case '(' : s[n] = 1; break;
			case ')' : s[n] = -1; break;
			case '[' : s[n] = 2; break;
			case ']' : s[n] = -2; break;
			case '{' : s[n] = 3; break;
			case '}' : s[n] = -3; break;
			case '?' : s[n] = 5;
		}
	}
	
	r = dp(0, n - 1);
	if (ovf) printf("%05d", r);
	else printf("%d", r);
}