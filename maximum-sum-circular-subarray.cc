class Solution {
public:
    
    inline int dp(vector<int>& a, int l, int r, int sign) {
        int suff_m = sign * a[l];
        int m = sign * a[l];
        for (int i = l + 1; i <= r; i++) {
            suff_m = max(suff_m + sign * a[i], sign * a[i]);
            m = max(suff_m, m);
        }
        return m;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int m = A.size();
        if (!m) return 0;
        int s = 0;
        for (int i = 0; i < m; i++) s += A[i];
        int ans1 = dp(A, 0, m - 1, 1);
        int ans2 = s + dp(A, 0, m - 2, -1);
        int ans3 = s + dp(A, 1, m - 1, -1);
        return max(ans1, max(ans2, ans3));
    }
};
