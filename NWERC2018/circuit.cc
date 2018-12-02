#include <bits/stdc++.h>
#define PI 3.141592653589
#define max_n 1005

struct coordinate {
	double x;
	double y;
};

coordinate pos[max_n];
short int adj[max_n][max_n];
short int count = 0;
short int n;

void solve (int current_node, int parent) {
	for (int i = 1; i <= adj[current_node][0]; i++) {
		short int k = adj[current_node][i];
		if (k != parent) {
			pos[k].x = pos[current_node].x + cos(count * PI / n);
			pos[k].y = pos[current_node].y + sin(count * PI / n);
			count ++;
			solve(k, current_node);
		}
	}
}



int main () {
	scanf("%hd", &n);
	short int a, b;
	memset(adj, 0, sizeof(adj));
	for (int i = 0; i < n - 1; i++) {
		scanf("%hd%hd", &a, &b);
		a--;
		b--;
		adj[a][0]++;
		adj[a][adj[a][0]] = b;
		adj[b][0]++;
		adj[b][adj[b][0]] = a;
	}
	memset(pos, 0, sizeof(pos));
	solve(0, -1);
	for (int i = 0; i < n; i++) printf("%.8f %.8f\n", pos[i].x, pos[i].y);
	return 0;
}
