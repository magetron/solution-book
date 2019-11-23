#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class MovingAverage {
public:
    queue<int> q;
	ll tot;
	int s;

	MovingAverage(int size) : tot(0), s(size) { }

    double next(int val) {
		if (q.size() < s) {
			q.emplace(val);
			tot += val;
		} else {
			int f = q.front(); q.pop();
			q.emplace(val);
			tot += val - f;
		}
		return (double)tot / (q.size());	
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

