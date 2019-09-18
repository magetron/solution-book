#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    TreeNode* helper (vector<int>& nums, int l, int r) {
		if (l >= r) return NULL;
		int mid = l + (r - l) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root -> left = helper(nums, l, mid);
		root -> right = helper(nums, mid + 1, r);
		return root;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size());		
    }

	TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
		while (head) {
			arr.push_back(head -> val);
			head = head -> next;
		}
		return sortedArrayToBST(arr);
    }
};
