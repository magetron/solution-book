#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int cv : coins) {
                if (i - cv >= 0) dp[i] = min((dp[i - cv] == INT_MAX ? INT_MAX - 1 : dp[i - cv]) + 1, dp[i]);
            }
        }
        return (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }
};
