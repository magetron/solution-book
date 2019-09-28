#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
		vector<string> strs(nums.size());
		for (int i = 0; i < nums.size(); i++) strs[i] = to_string(nums[i]);
		sort(strs.begin(), strs.end(), [] (const string& a, const string& b) -> bool {
			return a + b > b + a;
		});	
        if (strs[0][0] == '0') return "0";
		string ans = "";
		for (auto s : strs) ans += s;
		return ans;
		//for (auto s : strs) cout << s << endl;
	}
};

int main () {
	Solution s;
	vector<int> nums{3,30,34,5,9};
	s.largestNumber(nums);
	return 0;
}
