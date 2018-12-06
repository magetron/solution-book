#include "stdio.h"

int main () {
	int tmp;
	short int flag = 1;
	while (scanf("%d", &tmp) != EOF) {
		if (tmp == 42) flag = 0;
		if (flag) printf("%d\n", tmp);
	}
	return 0;
}
