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
		ListNode* prev;
		while (head != NULL && head -> next != NULL && head -> val == head -> next -> val) {
			while (head != NULL && head -> next != NULL && head -> val == head -> next -> val) {
				prev = head;
				head = head -> next;
				delete prev;
			}
			if (head == NULL) return NULL;
			prev = head;
			head = head -> next;
			delete prev;
		}
		if (head == NULL) return NULL;
		ListNode* ret = head;
		while (head -> next != NULL) {
			ListNode* last = head;
			head = head -> next;
			while (head != NULL && head -> next != NULL && head -> val == head -> next -> val) {
				while (head != NULL && head -> next != NULL && head -> val == head -> next -> val) {
					prev = head;
					head = head -> next;
					delete prev;
				}
				if (head == NULL) { last -> next = NULL; return ret; }
				prev = head;
				head = head -> next;
				delete prev;
			}
			if (head == NULL) { last -> next = NULL; return ret; }
			last -> next = head;
		}
		return ret;
    }
};

int main () {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(2);
	n1 -> next = n2; n2 -> next = n3;
	Solution s;
	ListNode* head = s.deleteDuplicates(n1);
	while (head != NULL) {
		cout << head -> val << " ";
		head = head -> next;
	}
	return 0;
}
