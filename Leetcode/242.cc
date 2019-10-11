class Solution {
public:
    bool isAnagram(string s, string t) {
		vector<int> d(26, 0);
		for (auto ch : s) d[ch - 97]++;
		for (auto ch : t) 
			if (d[ch - 97] == 0) return false; else d[ch - 97]--;
		return s.length() == t.length();	
    }
};

