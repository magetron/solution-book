#include <cstdio>
#include <cstring>
#include <complex>
#define max_num 50005
#define max_n 200005

typedef std::complex<double> cplx;

const double PI = acos(-1.0);

inline unsigned int intrev(unsigned x) {
	x = (( x & 0x55555555U) << 1) | (( x & 0xAAAAAAAAU) >> 1);
	x = (( x & 0x33333333U) << 2) | (( x & 0xCCCCCCCCU) >> 2);
	x = (( x & 0x0F0F0F0FU) << 4) | (( x & 0xF0F0F0F0U) >> 4);
	x = (( x & 0x00FF00FFU) << 8) | (( x & 0xFF00FF00U) >> 8);
	x = (( x & 0x0000FFFFFU) << 16) | (( x & 0xFFFF0000U) >> 16);
	return x;
}

int fast_frounier_transformation(int sign, cplx * data, int n) {
	int d = 1 + __builtin_clz(n);
	double theta = sign * 2.0 * PI / n;
	for (int m = n; m >= 2; m >>= 1, theta *= 2) {
		cplx tri = cplx(cos(theta), sin(theta));
		cplx w = cplx(1, 0);
		for (int i = 0, mh = m >> 1; i < mh; i++) {
			for (int j = i; j < n; j += m) {
				int k = j + mh;
				cplx tmp = data[j] - data[k];
				data[j] += data[k];
				data[k] = w * tmp;
			}
			w *= tri;
		}
	}
	for (int i = 0; i < n; i++) {
		int j = intrev(i) >> d;
		if (j < i) swap(data[i], data[j]);
	}
	if (sign == -1)
		for (int i = 0; i < n; i++) data[i] = cplx(real(data[i]) / n, imag(data[i]));
	return 0;
}

int num[max_n];
int count[max_n];
long long ans[max_n];
cplx x[2 * max_n];

int main () {
	int n;
	scanf("%d", &n);
	std::memset(count, 0, sizeof(count));
	int z = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (num[i] == 0) z++;
		count[num[i] + max_num]++;
	}
	int len = 1;
	while (len < max_n) len <<= 1;
	for (int i = 0; i < max_n; i++) x[i] = cplx(1.0 * count[i], 0.0);
	fast_frounier_transformation(1, x, len);
	for (int i = 0; i < len; i++) x[i] = x[i] * x[i];
	fast_frounier_transformation(-1, x, len);
	std::memset(ans, 0, sizeof(ans));
	for (int i = 0; i < len; i++) ans[i] = (long long)(real(x[i]) + 0.5);
	for (int i = 0; i < n; i++) ans[2 * (num[i] + max_num)]--;
	long long aans = 0;
	for (int i = 0; i < n; i++) {
		aans += ans[num[i] + max_num * 2];
		if (num[i] == 0) aans -= (z - 1) * 2;
	}
	printf("%lld\n", aans);
	return 0;
}
