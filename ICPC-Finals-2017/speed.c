#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "limits.h"
#define error_range 0.000005
#define max_n 1000

int n;
int total_time;
int d[max_n];
int s[max_n];

short int test(double val) {
	double tt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] + val < 0) return 1;
		tt += d[i] * 1.0 / (s[i] + val);
	}
	//printf("tt = %lf\n", tt);
	if (tt == total_time) return 0;
	else if (tt > total_time) return 1;
	else if (tt < total_time) return -1;
}

double solve(double min, double max) {
	//printf("%lf %lf\n", min, max);
	double mid = (min + max) / 2;
	double gap = fabs(max - min);
	//printf("mid = %lf ", mid);
	short int is_valid = test(mid);
	if ((is_valid == 0) || (gap < error_range)) return mid;
	else if (is_valid == -1) return solve(min, mid);
	else if (is_valid == 1) return solve(mid, max);
}

int main () {
	//freopen("speed.in", "r", stdin);
	//freopen("speed.ans", "w", stdout);
	scanf("%d %d", &n, &total_time);
	double min = INT_MAX;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &d[i], &s[i]);
		if (s[i] < min) min = s[i];
	}
	min = - min;
	double max = 1e6 + 1e3;
	printf("%lf\n", solve(min, max));
	//fclose(stdin);
	//fclose(stdout);
}
