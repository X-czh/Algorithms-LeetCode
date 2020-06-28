/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode previous = null;
        ListNode current = head;
        ListNode last;
        
        int length = 0;
        while (current != null) {
            previous = current;
            current = current.next;
            length++;
        }
        last = previous;
        if (length == 0 || k % length == 0) {
            return head;
        }
        
        current = head;
        for (int i = 0; i < length - k % length; i++) {
            previous = current;
            current = current.next;
        }
        last.next = head;
        previous.next = null;
        
        return current;
    }
}