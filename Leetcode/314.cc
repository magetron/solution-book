#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

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
    
    void dfs (TreeNode* root, int cnt, int depth, map<int, vector<pair<int, int>>>& dict) {
        if (!root) return;
        dict[cnt].push_back({depth, root -> val});
        dfs(root -> left, cnt - 1, depth + 1, dict);
        dfs(root -> right, cnt + 1, depth + 1, dict);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<pair<int, int>>> dict;
        dfs(root, 0, 0, dict);
        vector<vector<int>> ans;
        for (auto& v : dict) {
            sort(v.second.begin(), v.second.end(), [] (const pair<int, int>&a, const pair<int, int>&b) -> bool {
                return a.first < b.first;
            });
            ans.push_back({});
            for (auto n : v.second) {
                ans.back().emplace_back(n.second);
            }
        }
        return ans;
    }
};
