#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
        stack<int> st;
		int ans = 0;
		for (int i = 0; i < heights.size(); i++) 
			if (st.empty() || heights[st.top()] < heights[i]) st.push(i);
			else {
				while (!st.empty() && heights[st.top()] >= heights[i]) {
					int pos = st.top();
					st.pop();
					int area = heights[pos] * (i - (st.empty() ? 0 : st.top() + 1));
					//cout << heights[pos] << " " << area << endl;
					ans = max(ans, area);
				}
				st.push(i);
			}

		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	vector<int> heights{2,1,5,6,2,3};
	cout << s.largestRectangleArea(heights) << endl;
	return 0;
}
