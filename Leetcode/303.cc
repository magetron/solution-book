class NumArray {
public:
    
    vector<int> ps;
    
    NumArray(vector<int>& nums) {
        ps = vector<int>(nums.size());
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            ps[i] = s;
        }
    }
    
    int sumRange(int i, int j) {
        return ps[j] - (i > 0 ? ps[i - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
