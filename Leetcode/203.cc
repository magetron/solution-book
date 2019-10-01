#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(-1);
		dummy -> next = head;
		ListNode* prev = dummy;
		while (head) {
			if (head -> val == val) {
				prev -> next = head -> next;
				delete head;
                head = prev -> next;
			} else {
				prev = head;
				head = head -> next;
			}
		}
		return dummy -> next;
    }
};

