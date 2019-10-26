class RandomizedSet {
public:

    unordered_map<int, int> dict;
    vector<int> ls;
    
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (dict.find(val) == dict.end()) {
            ls.push_back(val);
            dict[val] = ls.size() - 1;
            return true;
        } else return false;
    }
    
    bool remove(int val) {
        if (dict.find(val) != dict.end()) {
            int pos = dict[val];
            dict[ls.back()] = pos;
            dict.erase(val);
            swap(ls[pos], ls.back());
            ls.pop_back();
            return true;
        } else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % ls.size();
        return ls[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
