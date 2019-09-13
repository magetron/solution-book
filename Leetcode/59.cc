#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> ans(n, vector<int>(n, 0));
			int count = 1;
			int i = 0;
			int j = 0;
			while (n > 1) {
				for (int k = 0; k < n; k++) ans[i][j++] = count++;
				j--; i++;
				for (int k = 0; k < n - 1; k++) ans[i++][j] = count++;
				i--; j--;
				for (int k = 0; k < n - 1; k++) ans[i][j--] = count++;
				j++; i--;
				for (int k = 0; k < n - 2; k++) ans[i--][j] = count++;
				i++; j++;
				n -= 2;
			}
			if (n == 1) ans[i][j++] = count++;
			return ans;
		}
};
