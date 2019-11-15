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
	vector<int> n;

    NumArray(vector<int>& nums) {
		n = nums;
    }

    inline void update(int i, int val) {
   		n[i] = val;
	}

    int sumRange(int i, int j) {
		int sum = 0;
		for (int k = i; k <= j; k++)
			sum += n[k];
		return sum;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */


