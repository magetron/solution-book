#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#define max_q 2000005

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
	int left_child;
	int right_child;
	int height;
} node;

int max (int a, int b) {
	return a > b ? a : b;
}

int height (node *root) {
	return (root == NULL) ? 0 : root -> height;
}

node *new_node (int key, int left_child, int right_child) {
	node *tmp_node = (node *) malloc( sizeof(node) );
	tmp_node -> key = key;
	tmp_node -> left = NULL;
	tmp_node -> right = NULL;
	tmp_node -> height = 1;
	tmp_node -> left_child = left_child;
	tmp_node -> right_child = right_child;
	return tmp_node;
}

node *right_rotate (node *y) {
	node *x = y -> left;
	node *T2 = x -> right;

	x -> right = y;
	y -> left = T2;

	y -> height = max( height(y -> left), height(y -> right) ) + 1;
	x -> height = max( height(x -> left), height(x -> right) ) + 1;
	
	if (T2 != NULL) y -> left_child = T2 -> left_child + T2 -> right_child + 1; else y -> left_child = 0;
	x -> right_child = y -> left_child + y -> right_child + 1;

	return x;
}

node *left_rotate (node *x) {
	node *y = x -> right;
	node *T2 = y -> left;

	y -> left = x;
	x -> right = T2;

	x -> height = max( height(x -> left), height(x -> right) ) + 1;
	y -> height = max( height(y -> left), height(y -> right) ) + 1;

	if (T2 != NULL) x -> right_child = T2 -> left_child + T2 -> right_child + 1; else x -> right_child = 0;
	y -> left_child = x -> left_child + x -> right_child + 1;
	
	return y;
}

int get_balance_factor (node *root) {
	if (root == NULL) return 0;
	else return height(root -> left) - height(root -> right);
}

node *insert(node *root, int key) {
	// std bst insertion
	if (root == NULL) return new_node(key, 0, 0);
	if (key < root -> key) {
		root -> left = insert(root -> left, key);
		root -> left_child++;
	}
	else if (key > root -> key) {
		root -> right = insert(root -> right, key);
		root -> right_child++;
	}
	else return root;

	root -> height = max( height(root -> left), height(root -> right) ) + 1;

	int balance = get_balance_factor(root);

	// 4 cases for unbalanced node
	if ( (balance > 1) && (key < root -> left -> key) ) return right_rotate(root);

	if ( (balance < -1) && (key > root -> right -> key) ) return left_rotate(root);

	if ( (balance > 1) && (key > root -> left -> key) ) {
		root -> left = left_rotate(root -> left);
		return right_rotate(root);
	}

	if ( (balance < -1) && (key < root -> right -> key) ) {
		root -> right = right_rotate(root -> right);
		return left_rotate(root);
	}

	return root;
}

short int flag;

int find_by_key (node *root, int key) {
	if (root != NULL) {
		//printf("find by key (%d, %d)\n", root -> key, key);
		if (key > root -> key) return root -> left_child + 1 + find_by_key(root -> right, key);
		else if (key < root -> key) return find_by_key(root -> left, key);
		else return root -> left_child;
	} else {
		//printf("currently NULL\n");
		flag = 1;
		return -1;
	};
}
	
void in_order (node *root) {
	if (root != NULL) {
		printf("%d %d %d\n", root -> key, root -> left_child, root -> right_child);
		in_order(root -> left);
		in_order(root -> right);
	}
}



int main () {
	//freopen("SDITSAVL.in", "r", stdin);
	//freopen("SDITSAVL.ans", "w", stdout);
	int n;
	scanf("%d", &n);
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		short int op;
		int num;
		scanf("%hd%d", &op, &num);
		if (op == 1) {
			//printf("inserting %d\n", num);
			root = insert(root, num);
		}
		if (op == 2) {
			//printf("try to find %d\n", num);
			flag = 0;
			int rank = find_by_key(root, num) + 1;
			if (flag) printf("Data tidak ada\n"); else printf("%d\n", rank);
		}
		//in_order(root);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

