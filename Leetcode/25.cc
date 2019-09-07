#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        if (head == NULL) return NULL;
		stack<ListNode *> s;
		ListNode* ret = head;
		s.push(head);
		bool first = true;
		ListNode* last_prev;
		while (true) {
			for (int i = 0; i < k - 1; i++) {
				head = head -> next;
				if (head == NULL) return ret;
				s.push(head);
			}
			ListNode *first_next = head -> next;
			if (first) {
				ret = s.top();
				first = false;
			} else last_prev -> next = s.top();
			while (!s.empty()) {
				ListNode* cur = s.top();
				s.pop();
				cur -> next = s.empty() ? first_next : s.top();
				if (s.empty()) last_prev = cur;
			}
			//cout << last_prev -> val << endl;
			head = first_next;
			if (head == NULL) return ret;
			s.push(head);
		}		
		return ret;	
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	/*ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);*/
	n1 -> next = n2;
	/*n2 -> next = n3;
	n3 -> next = n4;
	n4 -> next = n5;*/
	Solution s;
	ListNode *head = s.reverseKGroup(n1, 2);
	while (head) {
		cout << head -> val << " ";
		head = head -> next;
	}
	return 0;
}
