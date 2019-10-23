/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    inline void preorder(TreeNode* root, map<int, vector<pair<int, int>>>& dict, int cnt, int lvl) {
        if (!root) return;
        dict[cnt].push_back({lvl, root -> val});
        preorder(root -> left, dict, cnt - 1, lvl + 1);
        preorder(root -> right, dict, cnt + 1, lvl + 1);    
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        map<int, vector<pair<int, int>>> dict;
        preorder(root, dict, 0, 0);
        vector<vector<int>> ans;
        for (auto& p : dict) {
            sort(p.second.begin(), p.second.end(), [] (const pair<int, int>& a, const pair<int, int>& b) -> bool {
                return a.first < b.first;
            });
            ans.push_back({});
            for (auto val : p.second) ans.back().push_back(val.second);            
        }
        return ans;
    }

};
