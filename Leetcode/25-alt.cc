#include "bits/stdc++.h"
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
 } ();

class Solution {
private:
    static inline ListNode* rotate(ListNode* s, int k, ListNode** prevLast) {
      ListNode* l = s;
      ListNode* r = s->next;
      ListNode* temp = l;
      for(int i = 0; i < k-1; i++){
        l->next = r->next;
        r->next = temp;
        temp = r;
        r = l->next;
      }
      if (*prevLast) (*prevLast)->next = temp;
      *prevLast = l;
      return temp;
    }
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr) return nullptr;
    ListNode* h = head;
    ListNode* new_head = nullptr;
    ListNode* prev_last = nullptr;
    bool rotate_once = false;
    while(true){
      ListNode* t = h;
      int c = 1;
      while(t && c <= k) {
        t = t->next;
        c++;
      }
      if (c != k + 1) return rotate_once ? new_head : head;
      else{
        if (!rotate_once) {
          rotate_once = true;
          new_head = rotate(h, k, &prev_last);
        } else rotate(h, k, &prev_last);
        h = t; 
      }
    }
    return head;
  }
};



