#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:

	vector<vector<int>> merge (int n, vector<vector<int>>& ps) {
		vector<vector<int>> g(n, vector<int>());
		for (auto p : ps) g[p[1]].push_back(p[0]);
		return g;
	}
			
	bool top_sort (int pos, vector<vector<int>>& g, vector<bool>& v, vector<bool>& f) {
        if (f[pos]) return true;
        else if (v[pos]) return false;
        else v[pos] = true;
		for (auto c : g[pos]) {
            bool res = top_sort(c, g, v, f);
            if (!res) return false;
		}
        f[pos] = true;
        return true;
	}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> v(numCourses, false);
		vector<bool> f(numCourses, false);
		auto g = merge(numCourses, prerequisites);
		for (int i = 0; i < numCourses; i++) {
			bool res = top_sort(i, g, v, f);
			if (!res) return false;
		}
        return true;
	}
};
