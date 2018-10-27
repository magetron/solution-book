#include "stdio.h"
#define modulo 1000000007

long long f(long long x) {
	long long i = 0;
	while (x > 1) {
		if (x % 2 == 0) x /= 2;
		else x++;
		i++;
	}
	return i % modulo;
}

long long ans(long long x) {
	if (x <= 1) return 0;
	else if (x % 2 == 1) 
		return (ans(x - 1) + f(x)) % modulo;
	else if (x % 2 == 0)
		return (x / 2 + x - 2 + 2 * ans(x / 2)) % modulo;
}

long long l, r;

int main () {
	scanf("%lld %lld", &l, &r);
	printf("%lld", (ans(r) - ans(l - 1) + modulo) % modulo);
	return 0;
}
