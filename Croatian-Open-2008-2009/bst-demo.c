#include "stdlib.h"
#include "stdio.h"

typedef struct node {
	int key;
	struct node* left;
	struct node* right;
} node;

node *new_node(int data) {
	node *tmp_node = (node *)malloc(sizeof(node));
	tmp_node -> key = data;
	tmp_node -> left = NULL;
	tmp_node -> right = NULL;
	return tmp_node;
}

node *add_node(node *cur_node, int data) {
	if (cur_node == NULL) return new_node(data);
	else if (data < cur_node -> key) {
		cur_node -> left = add_node(cur_node -> left, data);
		return cur_node;
	} else if (data >= cur_node -> key) {
		cur_node -> right = add_node(cur_node -> right, data);
		return cur_node;
	}
}

void print_inorder(node *root) {
	if (root != NULL) {
		print_inorder(root -> left);
		printf("%d ", root -> key);
		print_inorder(root -> right);
	}
	return;
}

int main () {
	node *root = NULL;
	root = add_node(root, 9);
	add_node(root, 2);
	add_node(root, 8);
	add_node(root, 5);
	add_node(root, 4);
	add_node(root, 3);
	print_inorder(root);
	return 0;
}
