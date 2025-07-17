#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
 
int main() {
	int N, i, j;
	scanf("%d", &N);
	long long* x = (long long*)calloc(N, sizeof(long long));
	long long* y = (long long*)calloc(N, sizeof(long long));
 
	for (i = 0; i < N; i++)
		scanf("%lld %lld", &x[i], &y[i]);
 
	long long sum1 = 0, sum2 = 0, Area;
	for (i = 0; i < N - 1; i++) {
		sum1 += x[i] * y[i + 1];
		sum2 += x[i + 1] * y[i];
	}
	sum1 += x[N - 1] * y[0];
	sum2 += x[0] * y[N - 1];
	
	Area = (sum1 - sum2);
	if (Area < 0)
		Area = -Area;
 
	printf("%lld", Area);
	free(x);
	free(y);
	return 0;
}

//652320935250, 236904371154918