class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        for (auto c : s) {
            if (c == 'A') countA++;
            if (countA > 1) break;
        }
        if (countA > 1) return false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'L') {
                int fwdL = 1;
                int j = i + 1;
                while (s[j] == 'L' && j < s.length()) j++;
                if (j - i > 2) return false;
            }
        }
        return true;
    }
};
