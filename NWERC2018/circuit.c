#include "stdlib.h"
#define max_children 1000

typedef struct node {
	struct node *parent;
	int children_count;
	struct node *children[max_children];
	int key, all_children_count;
	double x, y;
	double a_s, a_e;
} node;

node *new_node (int key, int children_count) {
	node *tmp = malloc(sizeof(node));
	tmp -> key = key;
	tmp -> children_count = 0;
	tmp -> all_children_count = 0;
	tmp -> parent = NULL;
	memset(tmp -> children, NULL, sizeof(tmp -> children));
	return tmp;
}

void add_node_under (node *root, int key) {
	node *tmp = malloc(sizeof(node));
	tmp -> key = key;
	tmp -> children_count = 0;
	root -> children[root -> children_count] = tmp;
	root -> children_count ++;
}



int main () {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", tmp_a, tmp_b);
		if (tmp_a > tmp_b) swap(tmp_a, tmp_b);
		tree[tmp_a][0] ++;
		tree[tmp_a][tree[tmp_a][0]] = tmp_b;
	}
	//read input into an array
	root = new_node(1, tree[1][0]);
	for (int i = 1; i <= n; i++) {
		
		
	}
