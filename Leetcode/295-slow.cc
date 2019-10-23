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
    
	multiset<int> s;

	MedianFinder() {
		
    }

    void addNum(int num) {
		s.insert(num);
	}

    double findMedian() {
		if (s.size() % 2 == 0) {
			auto it = s.begin();
			advance(it, s.size() / 2 - 1);
			int l = *it;
			it++;
			int r = *it;
			return (l * 1.0 + r * 1.0) / 2;
		} else {
			auto it = s.begin();
			advance(it, s.size() / 2);
			return *it;
		}
	}
};

