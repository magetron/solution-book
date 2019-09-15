#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if (matrix.size() == 0) return false;
    	if (matrix[0].size() == 0) return false;
		vector<int> index(matrix.size());
		for (int i = 0; i < matrix.size(); i++) index[i] = matrix[i][0];
		int l = 0;
		int r = index.size();
		int line_num = -1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if ((mid + 1 == index.size() && index[mid] <= target) || (mid + 1 < index.size() && index[mid] <= target && index[mid + 1] > target)) {
				line_num = mid;
				break;
			}
			else if (index[mid] < target) l = mid + 1;
			else r = mid;
		}
		if (line_num == -1) return false;
		vector<int>& line = matrix[line_num];
		l = 0;
		r = line.size();
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (line[mid] == target) return true;
			else if (line[mid] < target) l = mid + 1;
			else r = mid;
		}
		return false;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return 0;
}
