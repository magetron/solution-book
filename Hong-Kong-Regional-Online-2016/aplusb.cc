#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define max_n 200000
#define max 50000

const double PI = acos(-1.0);

struct complex {
	double r, i;
	complex(double real = 0.0, double imag = 0.0) {
		r = real;
		i = imag;
	}
	complex operator + (const complex &e) {
		return complex(r + e.r, i + e.i);
	}
	complex operator - (const complex &e) {
		return complex(r - e.r, i - e.i);
	}
	complex operator * (const complex &e) {
		return complex(r * e.r - i * e.i, r * e.i + i * e.r);
	}
};

complex x[2 * max_n + 5];


void change(complex *y, int len) {
	int i, j, k;
	for (i = 1, j = len / 2; i < len - 1; i++) {
		if (i < j) std::swap(y[i], y[j]);
		k = len / 2;
		while (j >= k) {
			j -= k;
			k >>= 1;
		}
		if (j < k) j +=k;
	}
}

void fast_founier_transformation(complex *y, int len, int sign) {
	change(y, len);
	for (int h = 2; h <= len; h <<= 1) {
		complex wn(cos(- sign * 2 * PI / h), sin (- sign * 2 * PI / h));
		for (int j = 0; j < len; j += h) {
			complex w(1, 0);
			for (int k = j; k < j + h / 2; k++) {
				complex u = y[k] , t = w * y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}
	if (sign == -1) for (int i = 0; i < len; i++) y[i].r /= len;
}

int num[max_n + 5];
int count[max_n + 5];
long long ans[2 * max_n + 5];

int main () {
	int n;
	scanf("%d", &n);
	memset(count, 0, sizeof(count));
	int z = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (!num[i]) z++;
		count[num[i] + max]++;
	}
	int len = 1;
	while (len < max_n) len <<= 1;
	for (int i = 0; i < max_n; i++) {
		x[i].r = 1.0 * count[i];
		x[i].i = 0;
	}
	fast_founier_transformation(x, len, 1);
	for (int i = 0; i < len; i++) x[i] = x[i] * x[i];
	fast_founier_transformation(x, len, -1);
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < len; i++) ans[i] = (long long) (x[i].r + 0.5);
	for (int i = 0; i < n; i++) ans[2 * (num[i] + max)]--;
	long long aans = 0;
	for (int i = 0; i < n; i++) {
		aans += ans[num[i] + max * 2];
		aans -= (z - (num[i] == 0)) * 2;
	}
	printf("%lld\n", aans);
	return 0;
}
