#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL) { }
};

class Solution {
	public:
		ListNode* rotateRight(ListNode* head, int k) {
			if (head == NULL) return NULL;
			ListNode* cur = head;
			int len = 1;
			while (cur -> next != NULL) {
				cur = cur -> next;
				len++;
			}
			k %= len;
			cur -> next = head;
			cur = head;
			for (int i = 0; i < len - k - 1; i++) cur = cur -> next;
			ListNode* first = cur -> next;
			cur -> next = NULL;
			return first;
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return 0;
}
