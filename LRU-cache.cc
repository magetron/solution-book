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
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    int cap = -1;
    
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        auto found = dict.find(key);
        if (found == dict.end()) return -1;
        int val = (*(*found).second).second;
        put(key, val);
        return val;
    }
    
    void put(int key, int value) {
        auto found = dict.find(key);
        if (found != dict.end()) ls.erase(dict[key]);
        ls.push_front({key, value});
        dict[key] = ls.begin();
        if (ls.size() > cap) {
            int tdkey = ls.back().first;
            ls.pop_back();
            dict.erase(tdkey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
