#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		if (head == NULL) return NULL;
        ListNode* prev;
		ListNode* pprev;
		ListNode* ret;
		bool swap = false;
		bool first = true;
		while (head) {
			if (!first) pprev = prev;
			prev = head;
			head = head -> next;
			swap = !swap;
			if (head != NULL && swap) {
				if (first) {
					ret = head;
					first = false;
				} else pprev -> next = head;
				prev -> next = head -> next;
				head -> next = prev;
				prev = head;
				head = head -> next;
			}
		}
		return ret;
    }
};

