#include "stdio.h"
#include "math.h"

short int n;

short int isPrime (long long check_num) {
	if (check_num == 1) return 0;
	int d = 2;
	int limit = trunc(sqrt(check_num));
	while ((check_num % d != 0) && (d <= limit)) d++;
	if (d == limit + 1) return 1;
	else return 0;
}

void do_work() {
	long long l, r;
	scanf("%lld%lld", &l, &r);
	for (long long i = l; i <= r; i ++) if ( isPrime(i) ) printf("%lld\n", i);
	printf("\n");
}

int main () {
	//freopen("PRIME1.ans", "w", stdout);
	scanf("%hd", &n);
	for (int i = 0; i < n; i++) do_work();
	//fclose(stdout);
	return 0;
}
