#include <bits/stdc++.h>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int countA = 0;
		ListNode* curA = headA;
		while (curA) {
			countA++;
			curA = curA -> next;
		}
		int countB = 0;
		ListNode* curB = headB;
		while (curB) {
			countB++;
			curB = curB -> next;
		}
		curA = headA;
		curB = headB;
		int gap = abs(countA - countB);
		if (countA > countB) for (int i = 0; i < gap; i++) curA = curA -> next;
		else for (int i = 0; i < gap; i++) curB = curB -> next;
		while (curA != curB) {
			curA = curA -> next;
			curB = curB -> next;
		}
		return curA;
    }
};

