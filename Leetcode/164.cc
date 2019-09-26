#include <bits/stdc++.h>
#pragma GCC optimise ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

struct Bucket {
	int min = INT_MAX;
	int max = INT_MIN;
	int size = 0;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		int nummax = INT_MIN;
		int nummin = INT_MAX;
		for (auto num : nums) {
			nummax = max(nummax, num);
			nummin = min(nummin, num);
		}
		if (nummax == nummin) return 0;
		int gap = (nummax - nummin) / (nums.size() - 1);
		if (gap == 0) gap = 1;
        int bucket_count = (nummax - nummin) / gap + 1;
		vector<Bucket> buckets(bucket_count);
		for (auto num : nums) {
			int index = (num - nummin) / gap;
			buckets[index].max = max(buckets[index].max, num);
			buckets[index].min = min(buckets[index].min, num);
			buckets[index].size++;
		}
		//for (auto b : buckets) cout << b.min << " " << b.max << " " << b.size << endl;
		int i = 0;
		int ans = 0;
		while (i < bucket_count - 1) {
			int j = i + 1;
			while (j < bucket_count && buckets[j].size == 0) j++;
			ans = max(ans, buckets[j].min - buckets[i].max);
			i = j;
		}
		return ans;
	}
};


int main () {
	Solution s;
	vector<int> nums{1,1,1,1,5,5,5,5};
	cout << s.maximumGap(nums) << endl;
	return 0;
}
