#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		void print_vector (vector<int>& a) {
			for (int i : a) cout << i << " ";
			cout << endl;
		}

		void dfs(vector<int>& cs, int l, int target, int sum, vector<int>& a, vector<vector<int>>& ans) {
			//cout << "sum = " << sum << endl;
			//print_vector(a);
			if (sum == target) {
				ans.push_back(a);
				return;
			}
			if (sum > target) return;
			int i = l; 
			while (i < cs.size()) {
				int j = i + 1;
				while (j < cs.size() && cs[j] == cs[i]) j++;
				j--;
				if (i == j) {
					a.push_back(cs[i]);
					dfs(cs, i + 1, target, sum + cs[i], a, ans);
					a.pop_back();
					i++;
				} else {
					for (int k = i; k <= j; k++) {
						//cout << "k = " << k << endl;
						int s = 0;
						for (int m = i; m <= k; m++) {
							a.push_back(cs[m]);
							s += cs[m];
						}
						dfs(cs, j + 1, target, sum + s, a, ans);
						for (int m = i; m <= k; m++) a.pop_back();
					}
					i = j + 1;
				}
			}
		}

		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			vector<vector<int>> ans;
			sort(candidates.begin(), candidates.end());
            vector<int> a;
			dfs(candidates, 0, target, 0, a, ans);
			return ans;
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> cands{10,1,2,7,6,1,5};
	Solution s;
	vector<vector<int>> ans = s.combinationSum2(cands, 8);
	for (auto as : ans) 
		s.print_vector(as);
	return 0;
}
