#include "stdio.h"

int main () {
	int n;
	scanf("%d", &n);
	if (n >= 3) printf("%d", n - 2); else printf("1");
	return 0;
}
