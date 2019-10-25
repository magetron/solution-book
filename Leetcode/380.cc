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
    /** Initialize your data structure here. */
    
	vector<int> data;
	unordered_map<int, int> dict;

	RandomizedSet() {
		srand(time(NULL));		
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
		if (dict.find(val) == dict.end()) {
			data.push_back(val);
			dict.insert({val, data.size() - 1});
			return true;
		} else return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
		if (dict.find(val) != dict.end()) {
            int pos = dict[val];
			swap(data.back(), data[pos]);
            dict[data[pos]] = pos;
			data.pop_back();
            dict.erase(val);
			return true;
		} else return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
		int r = rand() % data.size();
		return data[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

