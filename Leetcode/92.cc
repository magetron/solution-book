#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || m > n) return NULL;

		ListNode *dummy = new ListNode(0);
		dummy -> next = head;
		head = dummy;

		for (int i = 0; i < m - 1; i++) head = head -> next;
		ListNode *prev = head;

		ListNode *nodeA = head -> next;
		ListNode *nodeB = head -> next -> next;
		ListNode *nodeStart = nodeA;

		int count = 0;
		while (count < n - m) {
			nodeA -> next = nodeB -> next;
			nodeB -> next = nodeStart;
			nodeStart = nodeB;
			nodeB = nodeA -> next;
			count++;
		}

		prev -> next = nodeStart;

		return dummy -> next;

    }
};
