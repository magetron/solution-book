#include "bits/stdc++.h"

using namespace std;

int max3 (int a, int b, int c) {
	if (a > b && a > c) return a;
	else if (b > c) return b;
	else return c;
}

int get_max (int *st, int slow, int shigh, int low, int high, int cur) {
	//cout << slow << " " << shigh << endl;
	if (low <= slow && shigh <= high) return st[cur];
	else if (high < slow || shigh < low || low > high) return 0;
	
	int mid = (slow + shigh) / 2;
	int left_max = get_max(st, slow, mid, low, high, cur * 2);
	int right_max = get_max(st, mid + 1, shigh, low, high, cur * 2 + 1);
	return max3(left_max, right_max, left_max + right_max);
}

int rec_construct (int *arr, int *st, int low, int high, int cur) {
	if (low == high) {
		st[cur] = arr[low];
		return st[cur];
	}
	int mid = (low + high) / 2;
	int left_max = rec_construct(arr, st, low, mid, cur * 2);
	int right_max = rec_construct(arr, st, mid + 1, high, cur * 2 + 1);
	st[cur] = max3(left_max, right_max, left_max + right_max);
	return st[cur];
}
	
int *construct (int *arr, int size) {
	int height = (int)ceil(log2(size));
	int max_size = 2 * (int)pow(2, height) - 1;
	int *st = new int [max_size + 1];
	memset(st, 0, (max_size + 1) * sizeof(int));
	rec_construct(arr, st, 0, size - 1, 1);
	//for (int i = 1; i <= max_size; i++) cout << st[i] << " ";
	//cout << endl;
	return st;
}

int main () {
	freopen("GSS1.in", "r", stdin);
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	int *lst = construct(arr, n);
	int m;
	cin >> m;	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << get_max(st, 0, n - 1, x - 1, y - 1, 1);
	}
	fclose(stdin);
	return 0;
}
