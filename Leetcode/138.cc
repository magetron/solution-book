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
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
		Node* cur = head;
		while (cur) {
			Node* cpy = new Node(cur -> val, cur -> next, nullptr);
			cur -> next = cpy;
			cur = cpy -> next;
		}
		cur = head;
		Node* cpy_head = cur -> next;
		while (cur) {
			Node* cpy = cur -> next;
			cpy -> random = (cur -> random ? cur -> random -> next : nullptr);
			cur = cpy -> next;
		}
		cur = head;
		while (cur) {
			Node* cpy = cur -> next;
			cur -> next = cpy -> next;
			cpy -> next = (cur -> next ? cur -> next -> next : nullptr);
			cur = cur -> next;
		}
		return cpy_head;
    }
};