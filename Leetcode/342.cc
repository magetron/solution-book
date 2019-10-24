class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0 && __builtin_popcount(num) == 1 && ((int)log2(num)) % 2 == 0);
    }
};
