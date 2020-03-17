class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> dict2(nums2.begin(), nums2.end());
        unordered_set<int> inter;
        for (auto n1 : nums1) {
            if (dict2.find(n1) != dict2.end()) inter.insert(n1);
        }
        vector<int> ans(inter.begin(), inter.end());
        return ans;
    }
};
