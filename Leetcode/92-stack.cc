#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* reverseBetween (ListNode* head, int m, int n) {
			if (head == NULL || m > n) return NULL;
			ListNode* dummy = new ListNode(0);
			dummy -> next = head;
			head = dummy;
			int count = 0;
			for (int i = 0; i < m - 1; i++) head = head -> next;
			ListNode* prev = head;
			stack<ListNode *> st;
			for (int i = 0; i < n - m + 1; i++) {
				head = head -> next;
				st.push(head);
			}
			head = head -> next;
			ListNode* succ = head;
			prev -> next = st.top();
			ListNode *cur;
			while (!st.empty()) {
				cur = st.top();
				st.pop();
				if (st.empty()) break;
				cur -> next = st.top();
			}
			cur -> next = succ;
			return dummy -> next;
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);
	n1 -> next = n2;
	n2 -> next = n3;
	n3 -> next = n4;
	n4 -> next = n5;
	Solution s;
	ListNode *head = s.reverseBetween(n1, 2, 5);
	while (head) {
		cout << head -> val << " ";
		head = head -> next;
	}
	return 0;
}

