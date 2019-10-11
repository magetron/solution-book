#include<bits/stdc++.h>
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) ans.push_back(nums[dq.front()]);
			if (i >= k - 1 && nums[i - k + 1] == nums[dq.front()]) dq.pop_front();
		}
		return ans;
    }
};


int main () {
	Solution s;
	vector<int> n{1,3,-1,-3,5,3,6,7};
	auto ans = s.maxSlidingWindow(n, 3);
	for (auto i : ans) cout << i << " "; cout << endl;
	return 0;
}

