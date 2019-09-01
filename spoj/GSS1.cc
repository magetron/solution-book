#include "bits/stdc++.h"

using namespace std;

struct node {
	int p_max, s_max, max, s;
};

int max3 (int a, int b, int c) {
	if (a > b && a > c) return a;
	else if (b > c) return b;
	else return c;
}

int max (int a, int b) {
	return a > b ? a : b;
}

node get_max (node *st, int slow, int shigh, int low, int high, int cur) {
	if (low <= slow && shigh <= high) return st[cur];
	int mid = (slow + shigh) / 2;
	if (high <= mid) return get_max(st, slow, mid, low, high, cur * 2);
	if (low > mid) return get_max(st, mid + 1, shigh, low, high, cur * 2 + 1);
	node l = get_max(st, slow, mid, low, high, cur * 2);
	node r = get_max(st, mid + 1, shigh, low, high, cur * 2 + 1);
	node tmp;
	tmp.s = l.s + r.s;
	tmp.max = max3(l.max, r.max, l.s_max + r.p_max);
	tmp.p_max = max(l.p_max, l.s + r.p_max);
	tmp.s_max = max(r.s_max, r.s + l.s_max);
	return tmp;
}

node rec_construct (int *arr, node *st, int low, int high, int cur) {
	if (low == high) {
		st[cur].max = arr[low];
		st[cur].p_max = arr[low];
		st[cur].s_max = arr[low];
		st[cur].s = arr[low];
		return st[cur];
	}
	int mid = (low + high) / 2;
	node l = rec_construct(arr, st, low, mid, cur * 2);
	node r = rec_construct(arr, st, mid + 1, high, cur * 2 + 1);
	st[cur].s =  l.s + r.s;
	st[cur].max = max3(l.max, r.max, l.s_max + r.p_max);
	st[cur].p_max = max(l.p_max, l.s + r.p_max);
	st[cur].s_max = max(r.s_max, r.s + l.s_max);
	return st[cur];
}
	
node *construct (int *arr, int size) {
	int height = (int)ceil(log2(size));
	int max_size = 2 * (int)pow(2, height) - 1;
	node *st = new node[max_size + 1];
	memset(st, 0, (max_size + 1) * sizeof(int));
	rec_construct(arr, st, 0, size - 1, 1);
	//for (int i = 1; i <= max_size; i++) cout << st[i] << " ";
	//cout << endl;
	return st;
}

int main () {
	freopen("GSS1.in", "r", stdin);
	freopen("GSS1.ans", "w", stdout);
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	node *st = construct(arr, n);
	int m;
	cin >> m;	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << get_max(st, 1, n, x, y, 1).max << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
