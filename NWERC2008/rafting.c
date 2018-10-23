#include "stdio.h"
#include "string.h"
#include "math.h"
#define max_n 100
#define	max_t_case 100
#define max_dist 2000

typedef struct {
	double x,y,z;
} p_l;

int t_case;
p_l in_pol_p[max_n];
p_l out_pol_p[max_n];
int in_pol;
int out_pol;
p_l in_pol_l[max_n];
p_l out_pol_l[max_n];
double tmp, min;

int init () {
	memset(&out_pol_l, 0, sizeof(out_pol_l));
	memset(&in_pol_l, 0, sizeof(in_pol_l));
	memset(&out_pol_p, 0, sizeof(out_pol_p));
	memset(&in_pol_p, 0, sizeof(in_pol_p));
	min = max_dist;
	tmp = 0.0;
	return 0;	
}

p_l point_to_line (p_l a, p_l b) {
	p_l tmp; 
	tmp.x = (b.y - a.y); // a
	tmp.y = (a.x - b.x); // b
	tmp.z = (b.x * a.y - a.x * b.y); //c
	//printf("x = %lf, y = %lf, x = %lf, y= %lf\n", a.x, a.y, b.x, b.y);
	//printf("%lf * x + %lf * y + %lf = 0\n", tmp.x, tmp.y, tmp.z);
	return tmp;
}

double sqr (double a) {
	return a * a;
}

double dist_point_to_point (p_l a, p_l b) {
	return (sqrt(sqr(b.x - a.x) + sqr(b.y - a.y)));
}

double dist_point_to_line (p_l p, p_l l, p_l la, p_l lb) {
	if ( (p.x - la.x) * (lb.x - la.x) + (p.y - la.y) * (lb.y - la.y) < 0) return (dist_point_to_point(p, la));
	if ( (p.x - lb.x) * (la.x - lb.x) + (p.y - lb.y) * (la.y - lb.y) < 0) return (dist_point_to_point(p, lb));
	return (fabs(l.x * p.x + l.y * p.y + l.z) / sqrt(sqr(l.x) + sqr(l.y)));
}

/*int check_segment(p_l p, p_l la, p_l lb) {
	if ( (p.x >= la.x) && (p.x <= lb.x) ) return 1;
	else if ( (p.x <= la.x) && (p.x >= lb.x) ) return 1;
	else if ( (p.y >= la.y) && (p.y <= lb.y) ) return 1;
	else if ( (p.y <= la.y) && (p.y >= lb.y) ) return 1;
	return 0;
}*/

int main () {

	//freopen("rafting.in", "r", stdin);
	//freopen("rafting.ans", "w", stdout);


	scanf("%d", &t_case);
	
	for (int c = 0; c < t_case; c++) {
		init ();	
		scanf("%d", &in_pol);
		for (int i = 0; i < in_pol; i++) {
			scanf("%lf %lf", &in_pol_p[i].x, &in_pol_p[i].y);
			if (i > 0) in_pol_l[i - 1] = point_to_line(in_pol_p[i - 1], in_pol_p[i]);
		}
		in_pol_l[in_pol - 1] = point_to_line(in_pol_p[in_pol - 1], in_pol_p[0]); 
		
		scanf("%d", &out_pol);
		for (int i = 0; i < out_pol; i++) {
			scanf("%lf %lf", &out_pol_p[i].x, &out_pol_p[i].y);
			if (i > 0) out_pol_l[i - 1] = point_to_line(out_pol_p[i - 1], out_pol_p[i]);
		}
		out_pol_l[out_pol - 1] = point_to_line(out_pol_p[out_pol - 1], out_pol_p[0]);

		for (int i = 0; i < in_pol; i++) {
			for (int j = 0; j < out_pol - 1; j++) {
				//if (check_segment(in_pol_p[i], out_pol_p[j + 1], out_pol_p[j])) 
				tmp = dist_point_to_line(in_pol_p[i], out_pol_l[j], out_pol_p[j + 1], out_pol_p[j]);
				//else continue;
				if ((tmp < min) && (tmp > 0)) {
					min = tmp;
					//printf("%lf, %lf,\n %lf, %lf,\n %lf, %lf %lfin out\n", in_pol_p[i].x, in_pol_p[i].y, out_pol_p[j].x, out_pol_p[j].y, out_pol_p[j + 1].x, out_pol_p[j + 1].y, tmp);
				}
			}
		
			//if (check_segment(in_pol_p[i], out_pol_p[out_pol - 1], out_pol_p[0])) 
			tmp = dist_point_to_line(in_pol_p[i], out_pol_l[out_pol - 1], out_pol_p[0], out_pol_p[out_pol - 1]);
			//else continue;
			if ((tmp < min) && (tmp > 0)) {
				min = tmp;
				//printf("%d, %d, %lf in out\n", i, out_pol - 1, tmp);
			}
		}

		for (int i = 0; i < out_pol; i++) {
			for (int j = 0; j < in_pol - 1; j++) {
				//if (check_segment(out_pol_p[i], in_pol_p[j + 1], in_pol_p[j]))
				tmp = dist_point_to_line(out_pol_p[i], in_pol_l[j], in_pol_p[j + 1], in_pol_p[j]);
				//else continue;
				if ((tmp < min) && (tmp > 0)) {
					min = tmp;
					//printf("%d, %d, %lf out in\n", i, j, tmp);
				}
			}
			//if (check_segment(out_pol_p[i], in_pol_p[in_pol - 1], in_pol_p[0]))
			tmp = dist_point_to_line(out_pol_p[i], in_pol_l[in_pol - 1], in_pol_p[0], in_pol_p[in_pol - 1]);
			//else continue;	
			if ((tmp < min) && (tmp > 0)) {
				min = tmp;
				//printf("%lf, %lf,\n %lf %lf \n %lf, %lf out in\n", out_pol_p[i].x, out_pol_p[i].y, in_pol_p[0].x, in_pol_p[0].y, in_pol_p[in_pol - 1].x, in_pol_p[in_pol - 1].y);
			}
		}
		
		for (int i = 0; i < in_pol; i++)
			for (int j = 0; j < out_pol; j++) {
				tmp = dist_point_to_point(in_pol_p[i], out_pol_p[j]);
				if ((tmp < min) && (tmp > 0)) {
					min = tmp;
					//printf("%lf, %lf, %lf, %lf p p\n", in_pol_p[i].x, in_pol_p[i].y, out_pol_p[j].x, out_pol_p[j].y);
				} else continue;
			}

		
		printf("%.8f\n", min / 2);
	
					
	}

	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
	

