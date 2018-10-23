#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max_n 100010
#define max_h 1000000

int n, b_left;
int h[max_n];
int min =max_h;

int cmp(const void *p, const void *q) {
	int l = *(int *)p;
	int r = *(int *)q;
	return (r - l);
}

int main () {
	scanf("%d\n",&n);
	memset(h, 0, sizeof(h));
	for (int i = 0; i < n; i++) scanf("%d",&h[i]);
	qsort(h, n, sizeof(int), cmp);
	b_left = n;
	int ans;
	for (int i = 0; i < n - 1; i++) {
		ans = (i + 1) + h[i + 1];
		if (ans < min) min = ans;
	}
	if (min > n) min = n;
	printf("%d", min);
	return 0;
}

	
	
	
