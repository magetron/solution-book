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
    ListNode *detectCycle(ListNode *head) {
		if (head == nullptr) return nullptr;
    	ListNode *dummy = new ListNode(0);
		dummy -> next = head;
		ListNode *fast = dummy -> next -> next, *slow = dummy -> next;
		while (fast != nullptr && slow != nullptr && fast != slow) {
			fast = fast -> next;
			if (fast == nullptr) break;
			fast = fast -> next;
			slow = slow -> next;
		}
		if (fast == slow) {
			slow = dummy;
			while (slow != fast) {
				slow = slow -> next;
				fast = fast -> next;
			}
			return slow;
		} else return nullptr;
    }
};
