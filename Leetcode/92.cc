#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode* fake = new ListNode(0);
		fake -> next = head;
		head = fake;
		for (int i = 0; i < m - 1; i++) head = head -> next;
		ListNode* pre = head;
		ListNode* nodea = head -> next;
		ListNode* nodeb = head -> next -> next;
		ListNode* nodehead = nodea;
		int count = m;
		while (count < n) {
			nodea -> next = nodeb -> next;
			nodeb -> next = nodehead;
			nodehead = nodeb;
			nodeb = nodea -> next;
            count++;
		}
		pre -> next = nodehead;
		return fake -> next;
    }
};
