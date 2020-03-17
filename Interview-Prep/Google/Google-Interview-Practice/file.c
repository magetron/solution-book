#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max_children 105
#define max_path_length 105
#define hash_key 37
#define hash_mod 1000000009


typedef struct node {
	long long key;
	int number_child;
	struct node *children[max_children];
	struct node *parent;
} node;

node *create_tree (int data) {
	node *tmp = malloc(sizeof(node));
	tmp -> key = data;
	tmp -> number_child = 0;
	tmp -> parent = NULL;
	memset(tmp -> children, 0, sizeof(tmp -> children));
	return tmp;
}

void add_node_under (node *root, int data) {
	node *tmp = malloc(sizeof(node));
	tmp -> key = data;
	tmp -> parent = root;
	tmp -> number_child = 0;
	root -> children[root -> number_child] = tmp;
	root -> number_child ++;
}

long long path[max_path_length];
int path_length;

void parse (char str[max_path_length]) {
	memset(path, 0, sizeof(path));
	path_length = 0;
	int len = strlen(str) - 1;
	int loc = 0;
	for (int i = 0; i < len - 1; i++) {
		if ((i < len) && (str[i] == '/')) {
			//printf("i = %d\n", i); 
			long long h = 0;
			long long p = 1;
			int j;
			//printf("str = ");
			for (j = i + 1; str[j] != '/' && j < len; j++) {
				//printf("%c", str[j]);
				if ((str[j] >= 'a') && (str[j] <= 'z')) h = (h + (str[j] - 'a' + 1) * p) % hash_mod; else h = (h + (str[j] - '0' + 26 + 1) * p) % hash_mod;
				p = p * hash_key % hash_mod;
			}
			//printf("\n");
			path[loc] = h;
			//printf("hash = %lld\n", h);
			loc++;
			i = j - 1;
			//printf("len = %d\n", len);
		}
	}
	path_length = loc - 1;
	//printf("path length = %d\n", path_length);
}

void add_path_to_tree(node *root, int loc, int path_length) {
	//printf("root = %lld loc = %d path_length = %d\n", root -> key, loc, path_length);
	if (loc <= path_length) {
		int can_find = 0;
		for (int i = 0; i < root -> number_child; i++) 
			if (root -> children[i] -> key == path[loc]) {
				add_path_to_tree(root -> children[i], loc + 1, path_length);
				can_find = 1;
			}
		if (!can_find) {
			add_node_under(root, path[loc]);
			add_path_to_tree(root -> children[root -> number_child - 1], loc + 1, path_length);
		}
	} else return;
}

int ans = 0;

void check_path_to_tree(node *root, int loc, int path_length) {
	//printf("root = %lld loc = %d path_length = %d ans = %d\n", root -> key, loc, path_length, ans);
	if (loc <= path_length) {
		int can_find = 0;
		for (int i = 0; i < root -> number_child; i++) 
			if (root -> children[i] -> key == path[loc]) {
				check_path_to_tree(root -> children[i], loc + 1, path_length);
				can_find = 1;
			}
		if (!can_find) {
			ans ++;
			add_node_under(root, path[loc]);
			check_path_to_tree(root -> children[root -> number_child - 1], loc + 1, path_length);
		}
	} else return;
}


void print_tree(node *root, int cur_depth) {
	//printf("key = %lld, depth = %d", root -> key, cur_depth);
	for (int i = 0; i < root -> number_child; i++) print_tree(root -> children[i], cur_depth + 1);
	return;
}


void do_work (int case_num) {
	int n, m;
	scanf("%d %d\n", &n, &m);
	node *root = NULL;
	root = create_tree(-1);
	for (int i = 0; i < n; i++) {
		char str[max_path_length];
		fgets(str, max_path_length, stdin);
		parse(str);
		//printf("str = %s", str);
		add_path_to_tree(root, 0, path_length);
		//print_tree(root, 0);
	}
	ans = 0;
	for (int i = 0; i < m; i++) {
		char str[max_path_length];
		fgets(str, max_path_length, stdin);
		parse(str);
		check_path_to_tree(root, 0, path_length);
	}
	printf("Case #%d: %d\n", case_num + 1, ans);
}

int main () {
	freopen("file.in", "r", stdin);
	freopen("file.ans", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) do_work(i);	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
