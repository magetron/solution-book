#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if (!head) return true;
		if (!head -> next) return true;
		if (!head -> next -> next) {
			return (head -> val == head -> next -> val);
		}
		ListNode* dummy = new ListNode(-1);
		dummy -> next = head;
		head = dummy;
		ListNode* slow = dummy;
		ListNode* fast = dummy;
		ListNode* prev = dummy;
		while (fast) {
			fast = fast -> next;
			if (!fast) {
				fast = slow -> next;
				break;
			}
			fast = fast -> next;
			prev = slow;
			slow = slow -> next;
		}
		if (!fast) {
			fast = slow -> next;
			slow = prev;
		}
		ListNode* nodeA = dummy -> next;
		ListNode* nodeB = dummy -> next -> next;
		ListNode* nodeS = nodeA;
		while (nodeS != slow) {
			nodeA -> next = nodeB -> next;
			nodeB -> next = nodeS;
			nodeS = nodeB;
			nodeB = nodeA -> next;
		}
		dummy -> next = nodeS;
		/*ListNode* tmp = dummy;
		while (tmp) {
			cout << tmp -> val << " ";
			tmp = tmp -> next;
		}
		cout << fast -> val << endl;*/
		slow = dummy -> next;
		while (fast) {
			if (slow -> val != fast -> val) return false;
			else {
				slow = slow -> next;
				fast = fast -> next;
			}
		}
		return true;
    }
};

int main () {
	Solution s;
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);		
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(1);	
	n1 -> next = n2;
	n2 -> next = n3;
	n3 -> next = n4;
	cout << (s.isPalindrome(n1) ? "true" : "false") << endl;
	return 0;
}

