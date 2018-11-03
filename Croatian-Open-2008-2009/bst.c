#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "string.h"
#define max_n 300005


typedef struct {
	int prev;
	int next;
} node;

node nodes[max_n];
node closest[max_n];

int depth[max_n];
int a[max_n];
int n; 
long long ans;


int max(int a, int b) {
	if (a > b) return a; 
	else return b;
}

int main() {
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		nodes[i].prev = i - 1;
		nodes[i].next = i + 1;
	}
	
	nodes[1].prev = 0;
	nodes[n].next = 0;
	memset(depth, -1, sizeof(depth));

	for (int i = n; i > 0; i--) {
		closest[a[i]].prev = nodes[a[i]].prev;
		closest[a[i]].next = nodes[a[i]].next;
		nodes[nodes[a[i]].prev].next = nodes[a[i]].next;
		nodes[nodes[a[i]].next].prev = nodes[a[i]].prev;
	}
	
	ans = 0;
	for (int i = 1; i <= n; i++) {
		depth[a[i]] = max(depth[closest[a[i]].prev], depth[closest[a[i]].next]) + 1;
		ans += depth[a[i]];
		printf("%lld\n", ans);
	}
	return 0;
}
