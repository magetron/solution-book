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
    int firstMissingPositive(vector<int>& nums) {
        for (auto& n : nums) if (n <= 0 || n > nums.size()) n = 0;
        int modulo = nums.size() + 1;
        for (auto n : nums) if (n % modulo != 0) nums[n % modulo - 1] += modulo;
        for (int i = 0; i < nums.size(); i++) if (nums[i] < modulo) return i + 1;
        return modulo;
    }
};

int main () {
	Solution s;
	vector<int> nums{3,4,-1,1};
	cout << s.firstMissingPositive(nums) << endl;
	return 0;
}
	
