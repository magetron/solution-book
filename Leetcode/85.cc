#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		if (n == 0) return 0;
		vector<int> heights(n + 1, 0);
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) if (matrix[i][j] == '1') heights[j]++; else heights[j] = 0;
			//for (auto k : heights) cout << k << " ";
			//cout << endl;
			stack<int> mono_st;
			for (int j = 0; j < n + 1; j++)
				if (mono_st.empty() || heights[mono_st.top()] < heights[j]) mono_st.push(j);
				else {
					while (!mono_st.empty() && heights[mono_st.top()] >= heights[j]) {
						int h = heights[mono_st.top()];
						mono_st.pop();
						int w = (j - (mono_st.empty() ? 0 : mono_st.top() + 1));
						//cout << h << " " << w << " " << endl;
						ans = max(ans, h * w);
					}
					mono_st.push(j);
				}
		}
		return ans;		
    }		
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	vector<vector<char>> mat{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << s.maximalRectangle(mat) << endl;
	return 0;
}
