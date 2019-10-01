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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* nodea = head;
		ListNode* nodeb = head -> next;
		ListNode* nodeh = nodea;
		while (nodeb) {
			nodea -> next = nodeb -> next;
			nodeb -> next = nodeh;
			nodeh = nodeb;
			nodeb = nodea -> next;
		}
		return nodeh;
    }
};

