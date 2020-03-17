class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.size() == 0) return 0;
        
        if (k >= prices.size() / 2) {
            int ans = 0;
            for (int i = 0; i < prices.size() - 1; i++) {
                ans += max(prices[i + 1] - prices[i], 0);
            }
            return ans;
        }
        
        int* states = new int[2 * k];
        for (int i = 0; i < k; i++) {
            states[2 * i] = INT_MIN;
            states[2 * i + 1] = 0;
        }
        for (int i = 0; i < prices.size(); i++) {
            for (int j = k - 1; j >= 0; j--) 
                if (j != 0) {
                    states[2 * j + 1] = max(states[2 * j + 1], prices[i] + states[2 * j]);
                    states[2 * j] = max(states[2 * j], -prices[i] + states[2 * j - 1]);
                } else {
                    states[1] = max(states[1], prices[i] + states[0]);
                    states[0] = max(states[0], -prices[i]);
                }        
        }
        int ans = states[2 * k - 1];
        delete [] states;
        
        return ans;
    }
};
