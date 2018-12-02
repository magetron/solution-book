#include <bits/stdc++.h>
#define error 0.0000001

using namespace std;

struct point {
	int x;
	int y;
};

point a, b, c;

double sqr (double a) {
	return a * a;
}

double distance (point a, point b) {
	return sqr((double) abs(a.x - b.x)) + sqr((double) abs(a.y - b.y));
}

bool isTriangle (point a, point b, point c) {
	double area = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
	if (area == 0) return false;
	else return true;
}

char *judge_angle (double A, double B, double C) {
	double min = INT_MAX;
	double max = -INT_MAX;
	double mid = 0;
	if ( (C >= A) && (C >= B) ) {
		max = C;
		if (A > B) {
			mid = A;
			min = B;
		} else {
			mid = B;
			min = A;
		}
	} else if ( (B >= A) && (B >= C) ) {
		max = B;
		if (A > C) {
			mid = A;
			min = C;
		} else {
			min = C;
			mid = A;
		}
	} else if ( (A >= B) && (A >= C) ) {
		max = A;
		if (B > C) {
			mid = B;
			min = C;
		} else {
			mid = C;
			min = B;
		}
	}
	double tmp1 = min + mid;
	double tmp2 = max;
	if ((tmp1 == tmp2)) return "right";
	else if (tmp1 < tmp2) return "obtuse";
	else return "acute";
}
	
char *judge_length (double A, double B, double C) {
	if ((A == B) || (B == C) || (C == A)) return "isosceles";
	else return "scalene";
}

void do_work(int case_num) {
	scanf("%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
	double A = distance(b, c);
	double B = distance(a, c);
	double C = distance(a, b);
	if (isTriangle(a, b, c)) {
		printf("Case #%d: %s %s triangle\n", case_num, judge_length(A, B, C), judge_angle(A, B, C));
	} else {
		printf("Case #%d: not a triangle\n", case_num);
	}
	return;
}

int n;

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) do_work(i);
	return 0;
}
