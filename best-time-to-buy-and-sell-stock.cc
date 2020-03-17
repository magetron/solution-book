class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            sell2 = max(sell2, prices[i] + buy2);
            buy2 = max(buy2, sell1 - prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy1 = max(buy1, -prices[i]);
        }
        return sell2;
    }
};
