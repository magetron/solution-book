#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
	public:
		ListNode* sortList(ListNode* head) {
			vector<int> list;
			ListNode* cur = head;
			while (cur) {
				list.push_back(cur -> val);
				cur = cur -> next;
			}
			sort(list.begin(), list.end());
			cur = head;
			for (int i : list) {
				cur -> val = i;
				cur = cur -> next;
			}
			return head;
		}
};
