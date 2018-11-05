#include "stdio.h"

int is_distinct(int i, int j, int k) {
	if ( (i != j) && (j != k) && (i != k) ) return 1;
	else return 0;
}

int n;
int a[200005];

int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int count = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < n; k++) if ((a[i] + a[j] == a[k]) && is_distinct(i, j, k)) count ++;

	printf("%d\n", count);
}

