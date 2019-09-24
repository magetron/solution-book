#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};


static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
		if (!head) return nullptr;
    	ListNode* dummy = new ListNode(INT_MIN);
		dummy -> next = head;
		ListNode* prec = head;
		ListNode* cur = head -> next;
		ListNode* pren;
		ListNode* n = dummy;
		while (cur) {
			bool swapped = false;
			while (n != cur) {
				if (n -> val <= cur -> val && n -> next != cur && n -> next -> val > cur -> val) {
					//cout << n -> val << " " << cur -> val << endl;
					swapped = true;
					prec -> next = cur -> next;
					cur -> next = n -> next;
					n -> next = cur;
					break;
				}
				pren = n;
				n = n -> next;
			}
			if (swapped) cur = prec -> next; else {
				prec = cur;
				cur = cur -> next;
			}
			n = dummy;

			//ListNode* t = dummy;
			//while (t) {
			//	cout << t -> val << " ";
			//	t = t -> next;
			//}
			//cout << endl;
		}
		return dummy -> next;	
    }
};

int main () {
	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(5);
	ListNode* n3 = new ListNode(9);
	ListNode* n4 = new ListNode(2);
	ListNode* n5 = new ListNode(1);
	ListNode* n6 = new ListNode(0);
	ListNode* n7 = new ListNode(-1);
	n1 -> next = n2;
	n2 -> next = n3;
	n3 -> next = n4;
	n4 -> next = n5;
	n5 -> next = n6;
	n6 -> next = n7;
	Solution s;
	auto head = s.insertionSortList(n1);
	while (head) {
		cout << head -> val << " ";
		head = head -> next;
	}
	cout << endl;
	return 0;
}

