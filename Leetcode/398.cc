class Solution {
public:
    
    vector<int>& n;
    
    Solution(vector<int>& nums) : n(nums) {
        srand(time(NULL));
    }
    
    int pick(int target) {
        int d = 1;
        int ans = -1;
        for (int i = 0; i < n.size(); i++)
            if (n[i] == target) {
                if (rand() % d == 0) ans = i;
                d++;
            }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
