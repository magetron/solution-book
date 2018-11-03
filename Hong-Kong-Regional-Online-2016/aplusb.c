#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max_n 200000
#define max_sum 100000

int cmp(const void *p, const void *q) {
	int l = *(int *)p;
	int r = *(int *)q;
	return l - r;
}

int n;
int a[max_n];
int ans[max_sum][2];
long long ans_s;

int init () {
	memset(a, 0, sizeof(a));
	memset(ans, 0, sizeof(ans));
	ans_s = 0;
	return 0;
}

int main () {
	scanf("%d", &n);
	init();
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);
	//for (int i = 0; i < n; i++) printf("%d ", a[i]);
	for (int i = 0; i < n; i++) 
		for (int j = i; j < n; j++) {
			ans[a[i] + a[j] + max_sum / 2][0] = 1; 
			if (i != j) ans[a[i] + a[j] + max_sum / 2][1] += 2;
		}
	for (int i = 0; i < n; i++) if (ans[a[i] + max_sum / 2][0] == 1) ans_s += ans[a[i] + max_sum / 2][1];
	printf("%lld\n", ans_s);
	return 0;
}

	
