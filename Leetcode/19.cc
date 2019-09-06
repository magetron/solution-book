#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	// Fast and slow algo
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* fast = head;
		ListNode* slow = head;
        ListNode* ret = head;
		ListNode* prev;
		int fast_count = 0;
		while (fast && fast_count < n) {
			fast_count++;
			fast = fast -> next;
		}
		if (!fast) return head -> next;
		while (fast) {
			prev = slow;
			slow = slow -> next;
			fast = fast -> next;
		}
        prev -> next = slow -> next;
        delete slow;
        return ret;
	}
};

