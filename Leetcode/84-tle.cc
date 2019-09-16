#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 0) return 0;
		vector<int> right(heights.size());
		vector<int> left(heights.size());
		
		right[heights.size() - 1] = 0;
		for (int i = heights.size() - 2; i >= 0; i--) 
			if (heights[i] > heights[i + 1]) right[i] = 0; else {
				int j = i + 1;
				while (j < heights.size() && heights[j] >= heights[i]) j += (right[i] + 1);
				right[i] = j - i - 1;
			}
		
		left[0] = 0;
		for (int i = 1; i < heights.size(); i++)
			if (heights[i - 1] < heights[i]) left[i] = 0; else {
				int j = i - 1;
				while (j >= 0 && heights[j] >= heights[i]) j -= (left[i] + 1);
				left[i] = i - j - 1;
			}

		int ans = 0;
		for (int i = 0; i < heights.size(); i++) ans = max(ans, heights[i] * (left[i] + right[i] + 1));

		return ans;
    }

};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	cout << s.largestRectangleArea(heights) << endl;
	return 0;
}

