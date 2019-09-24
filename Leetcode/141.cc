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
    bool hasCycle(ListNode *head) {
		if (head == nullptr) return false;
		ListNode* dummy = new ListNode(0);
		dummy -> next = head;
    	ListNode* fast = dummy -> next -> next, *slow = dummy -> next;
		while (fast != nullptr && slow != nullptr && fast != slow) {
			fast = fast -> next;
			if (fast == nullptr) break;
			fast = fast -> next;
			slow = slow -> next;
		}
		return fast == slow; 
    }
};
