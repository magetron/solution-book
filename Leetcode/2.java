/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode newNode, prevNode = null, retNode = null;
		boolean extra1 = false;
		boolean first = true;
		while (l1 != null && l2 != null) {
			newNode = new ListNode(l1.val + l2.val);
			if (first) {
				retNode = newNode;
				first = false;
			}
			if (extra1) {
				newNode.val++;
				extra1 = false;
			}
			if (newNode.val >= 10) {
				extra1 = true;
				newNode.val -= 10;
			}
			if (prevNode != null) prevNode.next = newNode;
			prevNode = newNode;
			l1 = l1.next;
			l2 = l2.next;
		}
		while (l1 != null) {
			newNode = new ListNode(l1.val);
			if (extra1) {
				newNode.val ++;
				extra1 = false;
			}
			if (newNode.val >= 10) {
				extra1 = true;
				newNode.val -= 10;
			}
			prevNode.next = newNode;
			prevNode = newNode;
			l1 = l1.next;
		}
		while (l2 != null) {
			newNode = new ListNode(l2.val);
			if (extra1) {
				newNode.val ++;
				extra1 = false;
			}
			if (newNode.val >= 10) {
				extra1 = true;
				newNode.val -= 10;
			}
			prevNode.next = newNode;
			prevNode = newNode;
			l2 = l2.next;
		}
		if (extra1) {
			newNode = new ListNode(1);
			prevNode.next = newNode;
			prevNode = newNode;
		}
		return retNode;
	}
}
