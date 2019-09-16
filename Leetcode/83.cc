#include <bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode *prev;
		while (head != NULL && head -> next != NULL && head -> val == head -> next -> val) {
			prev = head;
			head = head -> next;
			delete prev;
		}
		if (head == NULL) return NULL;
		ListNode *ret = head;
		while (head -> next != NULL) {
			ListNode* last = head;
			head = head -> next;
			while (head != NULL && head -> next != NULL && head -> val == head -> next -> val) {
				prev = head;
				head = head -> next;
				delete prev;
			}
			if (head == NULL) {
				last -> next = NULL;
				return ret;
			}
			last -> next = head;
		}
		return ret;
    }
};

