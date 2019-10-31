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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string ls = serialize(root -> left);
        string rs = serialize(root -> right);
        return to_string(root -> val) + "|" + ls + "|" + rs;
    }

    
    TreeNode* construct (string& data, int& pos) {
        if (pos == data.length() || data[pos] == '|') {
            pos += 1;
            return nullptr;
        }
        int i = pos + 1;
        while (data[i] != '|') i++;
        string num = data.substr(pos, i - pos);
        TreeNode* root = new TreeNode(stoi(num));
        pos = i + 1;
        root -> left = construct(data, pos);
        root -> right = construct(data, pos);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return construct(data, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
