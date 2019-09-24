#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
  		if (head == nullptr) return;
		ListNode* dummy = new ListNode(0);
		dummy -> next = head;
		ListNode* fast = dummy -> next -> next, *slow = dummy -> next;
		while (fast) {
			fast = fast -> next;
			if (fast == nullptr) break;
			fast = fast -> next;
			slow = slow -> next;
		}
		ListNode* med = slow;
		ListNode* nodea = slow -> next;
        if (!nodea) return;
		ListNode* nodeb = slow -> next -> next;
		ListNode* nodes = nodea;
		while (nodeb) {
			nodea -> next = nodeb -> next;
			nodeb -> next = nodes;
			nodes = nodeb;
			nodeb = nodea -> next;
		}
        med -> next = nodes;
        
        /*ListNode* n = head;
        while (n) {
            cout << n -> val << " ";
            n = n -> next;
        }
        cout << endl;*/
        
        ListNode* m = med -> next;
		ListNode* cur = head;
        med = med -> next;
        bool even = false;
		while (med) {
            cout << med -> val << endl;
			ListNode* tmp = cur -> next;
            ListNode* mtmp = med -> next;
			cur -> next = med;
			med -> next = (tmp == m) ? nullptr : tmp;
            if (!med -> next) even = true;
			cur = tmp;
			med = mtmp;
		}
        if (!even) cur -> next = nullptr;
        
        /*n = head;
        while (n) {
            cout << n -> val << " ";
            n = n -> next;
        }
        cout << endl;*/
                
    }
};

