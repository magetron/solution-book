#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();


class RandomizedSet {
public:
    
	set<int> s;

	RandomizedSet() {
		srand(time(NULL));
    }

    bool insert(int val) {
		if (s.find(val) == s.end()) {
			s.insert(val);
			return true;
		} else return false;
    }

    bool remove(int val) {
		if (s.find(val) != s.end()) {
			s.erase(val);
			return true;
		} else return false;
    }

    int getRandom() {
        if (!s.size()) return -1;
		auto it = s.begin();
		int r = rand() % s.size();
		advance(it, r);
		return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

