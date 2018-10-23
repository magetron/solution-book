#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define max_b 20
#define max_t 100

int b;
int v[max_b];
int v_tot = 0;
int t,m;
int t_b[max_t];
int max = (1 << max_b);

int cmp (const void *p, const void *q) {
	int l = __builtin_popcount(*(int *)p);
	int r = __builtin_popcount(*(int *)q);
	return (l < r);
}

int init () {
	scanf("%d",&b);
	memset(v, 0, sizeof(v));
	for (int i = 0; i < b; i++) {
		scanf("%d",&v[i]);
		v_tot += v[i];
	}
	scanf("%d",&t);
	memset(t_b, 0, sizeof(t_b));
	for (int i = 0; i < t; i++) {
		scanf("%d",&m);
		for (int j = 0; j < m; j++) {
			int tmp;
			scanf("%d",&tmp);
			t_b[i] = t_b[i] | (1 << (tmp - 1));
		}
	}
	return 0;
}


int sort () {
	qsort(t_b, t, sizeof(int), cmp);
	return 0;
}

int check (int bb, int h, int c) {
	if (c >= max) return 1;
	if (bb == -1) {
		max = c;
		return 0;
	}

	if (t_b[bb] & h) return check(bb - 1, h, c);
	for (int i = b; i >= 0; i--) if (t_b[bb] & (1 << i)) check(bb - 1, h | (1 << i), c + v[i]);
}

int main () {
	init();
	//sort();
	check(t - 1, 0, 0);
	printf("%d\n",v_tot - max);
	return 0;
}
