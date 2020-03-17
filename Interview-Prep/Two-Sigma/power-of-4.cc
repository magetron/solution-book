class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0 && (num % 3 == 1) && ((num & (num - 1)) == 0));
    }
};
