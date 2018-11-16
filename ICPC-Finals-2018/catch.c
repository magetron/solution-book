#include <cstdio>
#include <vector>
#define max_n 1000000

int m, n;
long long k;

typedef struct {
	int u, v;
	long long s, t;
	double p;
} bus;

std :: vector<bus> b;

int init () {
	scanf("%d%d", &m, &n);
	scanf("%lld", &k);
	for (int i = 0; i < m; i++) {
		int u, v;
		long long s, t;
		double p;
		scanf("%d%d%lld%lld%lf", &u, &v, &s, &t, &p);
		if (t > k) continue;
		b.push_back({u, v, s, t, p});
	}
	return 0;
}


