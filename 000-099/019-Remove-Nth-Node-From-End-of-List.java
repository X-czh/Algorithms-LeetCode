/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode current = dummyHead;
        for (int i = -1; i < n; i++) {
            current = current.next;
        }
        ListNode nPlusOneDelayed = dummyHead;
        
        while (current != null) {
            current = current.next;
            nPlusOneDelayed = nPlusOneDelayed.next;
        }
        nPlusOneDelayed.next = nPlusOneDelayed.next.next;
        
        return dummyHead.next;
    }
}