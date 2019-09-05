#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
 		int len = height.size();
		int l = 0;
		int r = len - 1;
		int ans = INT_MIN;
		while (l < r) {
			int area = (r - l) * (height[l] > height[r] ? height[r] : height[l]);
			if (area > ans) ans = area;
			if (height[l] > height[r]) r--; else l++;
		}
		return ans;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << s.maxArea(height) << endl;
	return 0;
}


	
