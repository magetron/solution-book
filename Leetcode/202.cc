class Solution {
public:
    inline int sqr (int a) {
        return a * a;
    }
    
    bool isHappy(int n) {
        vector<bool> map(900, false);
        int s = n;
        int i = 0;
        while (s > 0) {
            i += sqr(s % 10);
            s /= 10;
        }
        if (i == 1) return true;
        map[i] = true;
        int j = 0;
        while (1) {
            while (i > 0) {
                j += sqr(i % 10);
                i /= 10;
            }
            if (j == 1) return true;
            if (map[j] || j == n) return false;
            map[j] = true;
            i = j;
            j = 0;
        }
        return false;
    }
};
