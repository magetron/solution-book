class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [] (const string& a, const string& b) -> bool {
            return a.length() < b.length();
        });
        unordered_map<string, int> dp;
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            string& w = words[i];
            dp[w] = 1;
            for (int j = 0; j < w.length(); j++) {
                string nw = w.substr(0, j) + w.substr(j + 1, w.length() - j - 1);
                dp[w] = max(dp[w], (dp.find(nw) == dp.end() ? 0 : dp[nw]) + 1);
            }
            ans = max(ans, dp[w]);
        }
        return ans;
    }
};
