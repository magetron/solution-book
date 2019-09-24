#include <bits/stdc++.h>
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
    ListNode *detectCycle(ListNode *head) {
    	unordered_set<ListNode *> dict;
		while (head) {
			auto found = dict.find(head);
			if (found == dict.end()) dict.insert(head);
			else return head;
			head = head -> next;
		}
		return null;
    }
};
