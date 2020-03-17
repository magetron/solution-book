#include "stdio.h"
#include "string.h"
#define max_c 1005
#define max_p 1005

int n;
int a[max_p];

void do_work(int case_num) {
	int c;
	int p;
	scanf("%d", &c);
	scanf("%d", &p);
	int min_gap = max_c;
	int rec_a;
	int rec_b;
	int gap;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < p; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < i; j++) {
			gap = c - a[i] - a[j];
			if ((gap < min_gap) && (gap >= 0)) {
				min_gap = gap;
				rec_a = i;
				rec_b = j;
			}
		}
	}
	printf("Case #%d: %d %d\n", case_num + 1, rec_b + 1, rec_a + 1);
	return;
}

int main () {
	freopen("store.in", "r", stdin);
	freopen("store.ans", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) do_work(i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
