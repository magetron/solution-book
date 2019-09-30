class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
       if (a > b) swap(a, b); if (a > c) swap(a, c); if (b > c) swap(b, c);
	   if (c - a <= 2) return {0, 0};
	   return {min(c - b, b - a) <= 2 ? 1 : 2, c - a - 2};
    }
};
