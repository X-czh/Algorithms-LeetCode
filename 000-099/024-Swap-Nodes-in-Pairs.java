/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy;
        
        while (head != null && head.next != null) {
            ListNode second = head.next;
            
            // swap head and second
            prev.next = second;
            head.next = second.next;
            second.next = head;
            
            // iterate
            prev = head;
            head = head.next;
        }
        
        return dummy.next;
    }
}