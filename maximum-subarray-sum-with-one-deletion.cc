#pragma GCC optimize ("Ofast")

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> f(arr.size(), 0);
        vector<int> b(arr.size(), 0);
        int ans = INT_MIN;
        int suff_m = arr[0], m = arr[0];
        f[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            suff_m = max(suff_m + arr[i], arr[i]);
            m = max(suff_m, m);
            f[i] = suff_m;
        }
        ans = max(ans, m);
        suff_m = m = arr.back();
        b.back() = arr.back();
        for (int i = arr.size() - 2; i >= 0; i--) {
            suff_m = max(suff_m + arr[i], arr[i]);
            m = max(suff_m, m);
            b[i] = suff_m;
        }
        
        //for (auto i : f) cout << i << " "; cout << endl;
        //for (auto i : b) cout << i << " "; cout << endl;
        
        for (int i = 1; i < arr.size() - 1; i++) {
            m = max(m, f[i - 1] + b[i + 1]);
        }
        return max(ans, m);
    }
};
