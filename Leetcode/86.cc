#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(-1);
		ListNode* head2 = new ListNode(-1);
		ListNode* ret_head1 = head1;
		ListNode* ret_head2 = head2;
		while (head) {
			if (head -> val < x) { head1 -> next = head; head1 = head1 -> next; }
			else { head2 -> next = head; head2 = head2 -> next; }
			head = head -> next;
		}
		head1 -> next = NULL;
		head2 -> next = NULL;
		if (ret_head1 -> next == NULL && ret_head2 -> next == NULL) return NULL;
		if (ret_head1 -> next == NULL) return ret_head2 -> next;
		if (ret_head2 -> next == NULL) return ret_head1 -> next;
		head1 = ret_head1;
		while (head1 -> next != NULL) head1 = head1 -> next;
		head1 -> next = ret_head2 -> next;
		return ret_head1 -> next;
    }
};


