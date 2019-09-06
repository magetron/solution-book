#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	int get_length(ListNode* head) {
		int count = 0;
		while (head) {
			count++;
			head = head -> next;
		}
        return count;
	}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len = get_length(head) - n;
		ListNode *ret = head;
		ListNode *prev;
		if (len > 0) {
			while (len) {
				len--;
				prev = head;
				head = head -> next;
			}
			prev -> next = head -> next;
        	delete head;
		} else {
			ret = ret -> next;
			delete head;
		}
		return ret;	
    }
};
