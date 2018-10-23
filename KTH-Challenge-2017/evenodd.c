#include "stdio.h"
#define modulo 1000000007

long long l, r, s, i;

long long f(long long x) {
	long long i = 0;
	while (x > 1) {
		if (x % 2 == 0) x = x / 2;
		else x++;
		i++;
	}
	return i % modulo;
}

int main () {
	scanf("%lld %lld", &l, &r);
	s = 0;
	
	for (i = l; i <= r; i++) s = (s + f(i)) % modulo;
	
	printf("%lld\n", s);

	return 0;
}

