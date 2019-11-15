#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class NumArray {
public:
	vector<int> bit;
	vector<int> n;

    NumArray(vector<int>& nums) {
		n = vector<int>(nums.size(), 0);
		bit = vector<int>(nums.size() + 1);
		for (int i = 0; i < nums.size(); i++) update(i, nums[i]);
    }

    void update(int i, int val) {
		int cpy = val;
        val -= n[i];
        n[i] = cpy;
		i++;
		while (i < bit.size()) {
			bit[i] += val;
			i += i & (-i);
		}
    }

	inline int sum (int i) {
		i++;
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & (-i);
		}
		return s;
	}

    int sumRange(int i, int j) {
		return sum(j) - sum(i - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

