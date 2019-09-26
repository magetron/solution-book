#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    int compareVersion(string version1, string version2) {
    	int i = 0;
		int j = 0;
		while (i < version1.length() && j < version2.length()) {
			int ii = i + 1;
			while (ii < version1.length() && version1[ii] != '.') ii++;
			string v1 = version1.substr(i, ii - i);
			int jj = j + 1;
			while (jj < version2.length() && version2[jj] != '.') jj++;
			string v2 = version2.substr(j, jj - j);
			cout << v1 << " " << v2 << endl;
			int v1n = stoi(v1);
			int v2n = stoi(v2);
			if (v1n > v2n) return 1;
			else if (v1n < v2n) return -1;
			i = ii + 1;
			j = jj + 1;
		}
		while (i < version1.length()) {
			int ii = i + 1;
			while (ii < version1.length() && version1[ii] != '.') ii++;
			string v1 = version1.substr(i, ii - i);
			int v1n = stoi(v1);
			if (v1n > 0) return 1;
			i = ii + 1;
		}
		while (j < version2.length()) {
			int jj = j + 1;
			while (jj < version2.length() && version2[jj] != '.') jj++;
			string v2 = version2.substr(j, jj - j);
			int v2n = stoi(v2);
			if (v2n > 0) return -1;
			j = jj + 1;
		}
		return 0;
    }
};

int main () {
	Solution s;
	cout << s.compareVersion("1.0", "1.1") << endl;
	return 0;
}
