#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main () {
	srand(time(0));
	int n = rand() % 200000;
	printf("%d\n", n);
	for (int i = 0; i < n; i++) printf("%d ",rand() % 100000 - 50000);
	return 0;
}

