#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
	public:
		Node* connect(Node* root) {
			Node* head = nullptr;
			Node* lead = nullptr;
			Node* cur = root;
			while (cur) {
				while (cur) {
					if (cur -> left) {
						if (lead) lead -> next = cur -> left;
						else head = cur -> left;
						lead = cur -> left;
					}
					if (cur -> right) {
						if (lead) lead -> next = cur -> right;
						else head = cur -> right;
						lead = cur -> right;
					}
					cur = cur -> next;
				}
				cur = head;
				head = nullptr;
				lead = nullptr;
			}
			return root;
		}
};


