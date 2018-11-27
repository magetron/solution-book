#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#define max_n 200005

using namespace std;

int inflator [max_n];
int n;

int main () {
	memset(inflator, 0, sizeof(inflator));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &inflator[i]);
	sort(inflator, inflator + n);
	//for (int i = 0; i < n; i++) printf("%d ", inflator[i]);
	double min_rate = INT_MAX;
	bool impossible = false;
	for (int i = 0; i < n; i++) {
		double rate = inflator[i] * 1.0 / (i + 1);
		//printf("inflator = %d i = %d rate = %lf\n", inflator[i], i, rate);
		if (rate > 1) {
			impossible = true;
			break;
		} else if (min_rate > rate) min_rate = rate;
	}
	if (impossible) printf("impossible\n");
	else printf("%6f\n", min_rate);
	return 0;
}
