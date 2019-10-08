#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class LRUCache {
public:
	list<pair<int, int>> ls;
	unordered_map<int, list<pair<int,int>>::iterator> dict;
	int cap;

    LRUCache(int capacity) : cap(capacity) {    
    }
    
    int get(int key) {
		auto found = dict.find(key);
		if (found == dict.end()) return -1;
		int val = (*(*found).second).second;
		put(key, val);
		return val;
    }
    
    void put(int key, int value) {
        auto found = dict.find(key);
		if (found != dict.end()) ls.erase((*found).second);
		ls.push_front({key, value});
		if (found != dict.end()) (*found).second = ls.begin();
        else dict[key] = ls.begin();
		if (ls.size() > cap) {
            int key = ls.back().first;
            ls.pop_back();
            dict.erase(key);
        }
    }
};

