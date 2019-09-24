class LRUCache {
public:
	int cap;
	list<pair<int, int>> nodes;
	unordered_map<int, list<pair<int, int>>::iterator> hmap;

    LRUCache(int capacity) {
		cap = capacity;
    }
    
    int get(int key) {
        auto found = hmap.find(key);
		if (found != hmap.end()) {
			int val = (*(*found).second).second;
			put(key, val);
			return val;
		}
		return -1;
    }
    
    void put(int key, int value) {
        auto found = hmap.find(key);
		if (found != hmap.end()) nodes.erase((*found).second);
		else if (nodes.size() >= cap) {
			int tbd = nodes.back().first;
			nodes.pop_back();
			hmap.erase(tbd);
		} 
		nodes.push_front({key, value});
		hmap[key] = nodes.begin();
    }
};

