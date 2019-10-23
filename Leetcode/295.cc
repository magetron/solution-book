#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> l;
	priority_queue<int, vector<int>, greater<int>> r;

	MedianFinder() {
		
    }

    void addNum(int num) {
		if (l.size() == 0) {
			l.emplace(num);
		} else {
			if (num <= l.top()) l.emplace(num);
			else r.emplace(num);
			if (l.size() - r.size() == 2) {
				int val = l.top(); l.pop();
				r.emplace(val);
			} else if (r.size() - l.size() == 2) {
				int val = r.top(); r.pop();
				l.emplace(val);
			}
		}
    }

    double findMedian() {
		int tot = l.size() + r.size();
		if (tot % 2 == 1) {
			return (l.size() > r.size() ? l.top() : r.top());
		} else {
			return (l.top() * 1.0 + r.top() * 1.0) / 2;
		}
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

