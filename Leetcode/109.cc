#include <bits/stdc++.h>
#pragma clang optimize on

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	TreeNode* inorder (ListNode*& head, int l, int r) {
		if (l >= r) return NULL;
		TreeNode* root = new TreeNode(-1);
		int mid = l + (r - l) / 2;
		root -> left = inorder(head, l, mid);
 	    root -> val = head -> val;
		head = head -> next;
		root -> right = inorder(head, mid + 1, r);
		return root;
	}
		

    TreeNode* sortedListToBST(ListNode* head) {
		int len = 0;
		ListNode* org_head = head;
		while (head) { len++; head = head -> next; }
		return inorder(org_head, 0, len);
    }
};
