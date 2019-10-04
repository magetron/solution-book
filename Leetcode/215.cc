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
	
	int partition(vector<int>& nums, int low, int high) {
		int p = rand() % (high - low + 1) + low;
        swap(nums[p], nums[high]);
        p = nums[high];
		int i = low - 1;
		for (int j = low; j < high; j++) 
			if (nums[j] >= p) {
				i++;
				swap(nums[i], nums[j]);
			}
		swap(nums[i + 1], nums[high]);
		return i + 1;
	}

    int findKthLargest(vector<int>& nums, int k) {
  		int low = 0;
		int high = nums.size() - 1;
		k--;
		while (true) {
			if (low == high) return nums[low];
			int p = partition(nums, low, high);
			if (p == k) return nums[k];
			else if (p > k) high = p - 1;
			else low = p + 1;
		}
    }
};

int main () {
	Solution s;
	vector<int> nums{3,2,3,1,2,4,5,5,6};
	cout << s.findKthLargest(nums, 4) << endl;
	return 0;
}
