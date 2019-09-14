#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		void print (vector<int>& a) {
			for (auto i : a) cout << i << " ";
			cout << endl;
		}

		int trap(vector<int>& height) {
			vector<int> lmax(height.size());
			vector<int> rmax(height.size());
			for (int i = height.size() - 1; i >= 0; i--)
				if (i == height.size() - 1) lmax[i] = height[i];
				else lmax[i] = (height[i] > lmax[i + 1]) ? height[i] : lmax[i + 1];
			for (int i = 0; i < height.size(); i++) 
				if (i == 0) rmax[i] = height[i];
				else rmax[i] = (height[i] > rmax[i - 1]) ? height[i] : rmax[i - 1];
			//print(lmax);
			//print(rmax);
			int ans = 0;
			for (auto it = height.begin(); it != height.end(); it++) {
				int pos = it - height.begin();
				ans += ((lmax[pos] > rmax[pos]) ? rmax[pos] : lmax[pos]) - *it;
			}
			return ans;
		}

};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
	cout << s.trap(height) << endl;
	return 0;
}
