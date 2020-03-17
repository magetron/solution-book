#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max_n 805

long a[max_n][2];
long n;
long long ans;
long count;

typedef struct node{
	long key;
	struct node *left;
	struct node *right;
} node;

node *new_node (int data) {
	node *tmp_node = (node *)malloc(sizeof(node));
	tmp_node -> key = data;
	tmp_node -> left = NULL;
	tmp_node -> right = NULL;
	return tmp_node;
}

node *add_node (node *cur_node, int data) {
	if (cur_node == NULL) return new_node(data);
	else if (data < cur_node -> key) {
		cur_node -> left = add_node(cur_node -> left, data);
		return cur_node;
	} else if (data >= cur_node -> key) {
		cur_node -> right = add_node(cur_node -> right, data);
		return cur_node;
	}
}

void delete_tree (node *cur_node) {
	if (cur_node -> left != NULL) delete_tree(cur_node -> left);
	if (cur_node -> right != NULL) delete_tree(cur_node -> right);
	free(cur_node);	
	return;
}

void in_order_1 (node *root) {
	if (root != NULL) {
		in_order_1(root -> left);
		a[count][0] = root -> key;
		count ++;
		//printf("%d ", root -> key);
		in_order_1(root -> right);
	}
	return;
}

void in_order_2 (node *root) {
	if (root != NULL) {
		in_order_2(root -> right);
		a[count][1] = root -> key;
		count ++;
		//printf("%d ", root -> key);
		in_order_2(root -> left);
	}
	return;
}

void do_work(int case_num) {
	printf("Case #%d: ", case_num + 1);
	scanf("%ld", &n);
	memset(a, 0, sizeof(a));
	//count = 0;
	ans = 0;
	node *root1 = NULL;
	int tmp;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (i == 0) root1 = add_node(root1, tmp);
		else add_node(root1, tmp);
	}
	node *root2 = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (i == 0) root2 = add_node(root2, tmp);
		else add_node(root2, tmp);
	}
	count = 0;
	in_order_1(root1);
	count = 0;
	in_order_2(root2);
	for (int i = 0; i < n; i++) {
	//	printf("%d %d\n",a[i][0], a[i][1]);
		ans += a[i][0] * a[i][1];
	}
	//printf("\n");
	printf("%lld\n", ans);
	delete_tree(root1);
	delete_tree(root2);
	return;
}



int main () {
	freopen("scalar.in", "r", stdin);
	freopen("scalar.ans", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) do_work(i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

