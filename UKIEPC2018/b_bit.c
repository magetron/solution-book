#include "string.h"
#include "stdio.h"

#define max_s 50
#define max_b 50

int m,b,s;
long long b_s[max_b];
long long ans = 0;
char tmp;

int main () {
	scanf("%d %d %d", &m, &b, &s);
	memset(b_s, 0, sizeof(b_s));
	m--;

	for (int i = 0; i < b; i++) {
		scanf("%c", &tmp);
		for (int j = 0; j < s; j++) {
			scanf("%c", &tmp);
			b_s[i] |= (tmp - '0') << j;
		}
	}

	for (int i = 0; i < b; i++) if (b_s[i] & (1 << m)) ans |= b_s[i];
	
	ans &= ~(1 << m);
	printf("%d\n",__builtin_popcount(ans));
	return 0;
}
