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
    vector<int> majorityElement(vector<int>& nums) {
		if (nums.size() == 0) return {};
		if (nums.size() == 1) return {nums[0]};
		int a = -1, ca = 0;
		int b = -1, cb = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (ca <= 0 && nums[i] != b) {
				a = nums[i];
				ca = 0;
			}
			else if (cb <= 0 && nums[i] != a) {
				b = nums[i];
				cb = 0;
			}
			if (nums[i] == a) ca++;
			else if (nums[i] == b) cb++;
			else {
				ca--;
				cb--;
			}
			//cout << a << " " << ca << " " << b << " " << cb << endl;
		}
		ca = 0;
		cb = 0;
		for (int i = 0; i < nums.size(); i++) if (nums[i] == a) ca++; else if (nums[i] == b) cb++;
		if (ca > nums.size() / 3 && cb > nums.size() / 3) return {a, b};
        else if (ca > nums.size() / 3) return {a};
		else if (cb > nums.size() / 3) return {b};
        else return {};        
    }
};

int main () {
	Solution s;
	vector<int> a{8,8,7,7,7,7,5,5,5,5};
	auto ans = s.majorityElement(a);
	for (auto i : ans) cout << i << " ";
	cout << endl;
	return 0;
}
