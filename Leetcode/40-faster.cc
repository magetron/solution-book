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
			for (int i = l; i < cs.size(); i++) {
				if (cs[i] > target) break;
				if (i > l && cs[i - 1] == cs[i]) continue;
				a.push_back(cs[i]);
				dfs(cs, i + 1, target, sum + cs[i], a, ans);
				a.pop_back();
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
	Solution s;
	vector<int> cands{2,3,5};
	vector<vector<int>> ans = s.combinationSum(cands, 8);
	for (auto as : ans) s.print_vector(as);
	return 0;
}

