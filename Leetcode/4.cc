#include<bits/stdc++.h>

using namespace std;

int even_bin (vector<int>&a, vector<int>&b, int low, int high, int len_a, int len_b) {
	//cout << low << " " << high << endl;
	if (low >= high) return high;
	int i = low + (high - low) / 2;
	int j = (len_a + len_b) / 2 - i;
	if ((i > 0 && j > 0 && i < len_a && j < len_b) && (a[i] >= b[j - 1] && b[j] >= a[i - 1])) return i;
	else if ((j > 0 && i < len_a) && (a[i] >= b[j - 1])) return even_bin(a, b, low, i, len_a, len_b);
	else return even_bin(a, b, i + 1, high, len_a, len_b);
}

int odd_bin (vector<int>&a, vector<int>&b, int low, int high, int len_a, int len_b) {
	//cout << low << " " << high << endl;
	if (low >= high) return high;
	int i = low + (high - low) / 2;
	int j = (len_a + len_b - 1) / 2 - i;
	//cout << i << " " << j << endl;
	//cout << "------" << endl;
	if ((i > 0 && j > 0 && i < len_a && j < len_b) && (a[i] >= b[j - 1] && b[j] >= a[i - 1])) return i;
	else if ((j > 0 && i < len_a) && (a[i] >= b[j - 1])) return odd_bin(a, b, low, i, len_a, len_b);
	else return odd_bin(a, b, i + 1, high, len_a, len_b);
}

void print (vector<int>&a, vector<int>&b, int len_a, int len_b) {
	cout << len_a << " " << len_b << endl;
	for (int i = 0; i < len_a; i++) cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i < len_b; i++) cout << b[i] << " ";
	cout << endl;
}

double even (vector<int>&a, vector<int>&b, int len_a, int len_b) {
	int i = even_bin(a, b, 0, len_a, len_a, len_b);
	int j = (len_a + len_b) / 2 - i;
	//print(a, b, i, j);
	int max_left;
	if (i > 0 && j > 0) max_left = a[i - 1] > b[j - 1] ? a[i - 1] : b[j - 1];
	else if (i > 0) max_left = a[i - 1];
	else max_left = b[j - 1];
	int min_right;
	if (i < len_a && j < len_b) min_right = a[i] > b[j] ? b[j] : a[i];
	else if (i < len_a) min_right = a[i];
	else min_right = b[j];
	//cout << max_left << " " << min_right << endl;
	return (max_left + min_right) * 1.0 / 2;
}

double odd (vector<int>&a, vector<int>&b, int len_a, int len_b) {
	int i = odd_bin(a, b, 0, len_a, len_a, len_b);
	int j = (len_a + len_b - 1) / 2 - i;
	//print(a, b, i, j);
	if (i < len_a && j < len_b) return a[i] > b[j] ? b[j] : a[i];
	else if (i < len_a) return a[i];
	else return b[j];
}

double findMedianSortedArrays (vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	if ((m + n) % 2 == 0) if (m <= n) return even(nums1, nums2, m, n); else return even(nums2, nums1, n, m);
	else if (m <= n) return odd(nums1, nums2, m, n); else return odd(nums2, nums1, n, m);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> a{4, 5};
	vector<int> b{1, 2};
	//cout << findMedianSortedArrays(a, b) << endl;
	return 0;
}
