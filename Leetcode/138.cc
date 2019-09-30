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
		Node* ans = cur -> next;
		while (cur) {
			cur -> next -> random = (cur -> random ? cur -> random -> next : nullptr);
            cur = cur -> next -> next;
		}
        cur = head;
        while (cur) {
            Node *succ = cur -> next -> next;
            if (!succ) {
                cur -> next -> next = nullptr;
                cur -> next = nullptr;
                break;
            }
            cur -> next -> next = succ -> next;
            cur -> next = succ;
            cur = succ;
        }
		return ans;
    }
};

