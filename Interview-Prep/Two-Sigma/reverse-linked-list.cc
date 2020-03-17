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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* nodeA = head;
        ListNode* nodeB = head -> next;
        if (!nodeB) return head;
        ListNode* nodeH = nodeA;
        while (nodeB) {
            nodeA -> next = nodeB -> next;
            nodeB -> next = nodeH;
            nodeH = nodeB;
            nodeB = nodeA -> next;
        }
        return nodeH;
    }
};
