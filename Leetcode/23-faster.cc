#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return NULL;
		vector<int> nums;
		for (auto it = lists.begin(); it != lists.end(); it++) {
			ListNode *head = *it;
			while (head) {
				nums.push_back(head -> val);
				head = head -> next;
			}
		}
		sort(nums.begin(), nums.end());
		//for (auto it = nums.begin(); it != nums.end(); it++) 
		//	cout << *it << " ";
		//cout << endl;
		auto it = nums.begin();
		if (it == nums.end()) return NULL;
		ListNode *head = new ListNode(*it);
		ListNode *ret = head;
		it++;
		while (it != nums.end()) {
			ListNode *cur = new ListNode(*it);
			head -> next = cur;
			head = head -> next;
			it++;
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
	vector<ListNode*> lists{n1_1, n2_1, n3_1};
	Solution s;
	ListNode* head = s.mergeKLists(lists);
	while (head) {
		cout << head -> val << " ";
		head = head -> next;
	}
	return 0;
}
