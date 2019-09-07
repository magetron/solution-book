#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {

	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		for (auto it = lists.begin(); it != lists.end(); it++) 
			if ((*it) == NULL) lists.erase(it--);
		if (lists.size() == 0) return NULL;
		ListNode* head;
		int min = INT_MAX;
		int pos;
    	for (auto it = lists.begin(); it != lists.end(); it++)
			if (*it != NULL && (*it) -> val < min) {
				pos = it - lists.begin();
				min = (*it) -> val;
				head = *it;
			}
		ListNode* ret = head;
		lists[pos] = lists[pos] -> next;
		while (true) {
			bool alldone = true;
			for (auto it = lists.begin(); it != lists.end(); it++)
				if (*it != NULL) {
					alldone = false;
					break;
				}
			if (alldone) break;

			int min = INT_MAX;
			int pos;
			for (auto it = lists.begin(); it != lists.end(); it++)
				if (*it != NULL && (*it) -> val < min) {
					pos = it - lists.begin();
					min = (*it) -> val;
				}
			head -> next = lists[pos];
			lists[pos] = lists[pos] -> next;
			head = head -> next;
		}
		return ret;
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ListNode* n1_1 = new ListNode(1);
	ListNode* n1_2 = new ListNode(4);
	ListNode* n1_3 = new ListNode(5);
	n1_1 -> next = n1_2;
	n1_2 -> next = n1_3;
	ListNode* n2_1 = new ListNode(1);
	ListNode* n2_2 = new ListNode(3);
	ListNode* n2_3 = new ListNode(4);
	n2_1 -> next = n2_2;
	n2_2 -> next = n2_3;
	ListNode* n3_1 = new ListNode(2);
	ListNode* n3_2 = new ListNode(6);
	n3_1 -> next = n3_2;
	ListNode* null1;
	ListNode* null2;
	vector<ListNode*> lists{null1, null2};
	Solution s;
	ListNode* head = s.mergeKLists(lists);
	while (head) {
		cout << head -> val << " ";
		head = head -> next;
	}
	return 0;
}
