#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class ZigzagIterator {
public:
	
	vector<int>& vec1;
	vector<int>& vec2;
	int p1, p2;
	bool c;

    ZigzagIterator (vector<int>& v1, vector<int>& v2) : vec1(v1), vec2(v2) {
		p1 = 0;
		p2 = 0;
        if (v1.size()) c = true; else c = false;
    }

    int next() {
		int val = (c ? vec1[p1] : vec2[p2]);
    	if (c) p1++; else p2++;
		c = !c;
		if ((c && p1 == vec1.size()) || (!c && p2 == vec2.size())) c = !c;
		return val;
	}

    bool hasNext() {
        return (c && p1 < vec1.size()) || (!c && p2 < vec2.size());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */


