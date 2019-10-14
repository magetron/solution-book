#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Vector2D {
public:
    vector<vector<int>> v;
	int m, n;

	Vector2D(vector<vector<int>>& vec) {
		v = vec;
		m = 0;
        while (m < v.size() && !v[m].size()) m++;
		n = 0;
    }

    int next() {
		int val = v[m][n];
		if (n == v[m].size() - 1) {
			do {
                m++;
            } while (m < v.size() && !v[m].size());
			n = 0;
		} else n++;
		return val;
    }

    bool hasNext() {
		return (m < v.size() && n < v[m].size());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
