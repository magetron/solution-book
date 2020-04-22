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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* it = head;
        bool carry = false;
        while (l1 || l2) {
            
            ListNode* new_node = new ListNode((l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + (carry ? 1 : 0));
            carry = false;
            it -> next = new_node; it = it -> next;
            
            if (new_node -> val >= 10) {
                carry = true;
                new_node -> val -= 10;
            }
            
            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
            
        }
        
        if (carry) it -> next = new ListNode(1);
        
        return head -> next;
        
    }
};
