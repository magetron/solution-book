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
    inline ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode* fast = head -> next, *slow = head;
        if (!fast) return nullptr;
		while (fast && fast != slow) {
			fast = fast -> next;
			if (!fast) return nullptr;
			fast = fast -> next;
			slow = slow -> next;
		}
		if (!fast) return nullptr;
        slow = head;
		fast = fast -> next;
		while (fast != slow) {
			fast = fast -> next;
			slow = slow -> next;
		}
		return fast;
    }
};


