#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int i = 0;
		int j = 0;
		int m = matrix.size();
		if (m == 0) return vector<int>();
        int n = matrix[0].size();
		if (n == 0) return vector<int>();
		int tot = m * n;
		vector<int> ans;
		while (n > 1 && m > 1) {
			cout << n << " " << m << endl;
			for (int k = 0; k < n; k++) ans.push_back(matrix[i][j++]);
			j--; i++;
			for (int k = 0; k < m - 1; k++) ans.push_back(matrix[i++][j]);
			i--; j--;
			for (int k = 0; k < n - 1; k++) ans.push_back(matrix[i][j--]);
			j++; i--;
			for (int k = 0; k < m - 2; k++) ans.push_back(matrix[i--][j]);
			i++; j++;
			m -= 2;
			n -= 2;
		}
        if (n == 1) for (int k = 0; k < m; k++) ans.push_back(matrix[i++][j]);
		else if (m == 1) for (int k = 0; k < n; k++) ans.push_back(matrix[i][j++]);
		return ans;
    }
};

int main () {
	vector<int> a1{1,2,3,4};
	vector<int> a2{5,6,7,8};
	vector<int> a3{9,10,11,12};
	vector<vector<int>> mat{a1, a2, a3};
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	auto ans = s.spiralOrder(mat);
	for (auto i : ans) cout << i << " ";
	cout << endl;
	return 0;
}

