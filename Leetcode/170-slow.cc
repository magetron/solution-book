class TwoSum {
public:		

	unordered_set<int> dict;
    unordered_set<int> twodict;

    TwoSum() {
	}
    
    void add(int number) {
        if (dict.find(number) != dict.end())
            twodict.insert(number);
		dict.insert(number);
    }
    
    bool find(int value) {
    	for (auto i : dict) {
            if (value == 2 * i) {
                if (twodict.find(i) != twodict.end()) return true;
            } else if (dict.find(value - i) != dict.end()) return true;
		}
		return false;
	}
};


