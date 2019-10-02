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

	vector<vector<int>> graphize (int n, vector<vector<int>>& prerequisites) {
		vector<vector<int>> g(n, vector<int>());
		for (auto p : prerequisites) g[p[1]].push_back(p[0]);
		return g;
	}

	
	bool top_sort (int pos, vector<vector<int>>& g, vector<bool>& f, vector<bool>& v, vector<int>& ans) {
		//cout << v[pos] << " " << f[pos] << endl;
		if (f[pos]) return true; 
		else if (v[pos]) return false;
		else v[pos] = true;
		for (auto ch : g[pos]) 
			if (!top_sort(ch, g, f, v, ans)) return false;
		ans.push_back(pos);
		f[pos] = true;
        return true;
	}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<bool> f(numCourses, false);
		vector<bool> v(numCourses, false);
		vector<int> ans;
		vector<vector<int>> g = graphize(numCourses, prerequisites);
		for (int i = 0; i < numCourses; i++) if (!v[i]) {
			if (!top_sort(i, g, f, v, ans)) return vector<int>();
        }
		reverse(ans.begin(), ans.end());
		return ans;
    }
};

int main () {
	Solution s;
	vector<vector<int>> p{{0,1}, {1,0}};
	auto ans = s.findOrder(2, p);
	for (auto i : ans) cout << i << " ";
	cout << endl;
	return 0;
}
