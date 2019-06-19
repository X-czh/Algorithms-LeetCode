/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null) // empty list
            return head;
        
        ListNode dummy = new ListNode(-1);
        
        while (head != null) {
            // find insertion position
            ListNode insert_pos = dummy;
            while (insert_pos.next != null && insert_pos.next.val < head.val) {
                insert_pos = insert_pos.next;
            }
            
            // insert
            ListNode temp = insert_pos.next;
            insert_pos.next = head;
            head = head.next;
            insert_pos.next.next = temp;
        }
        return dummy.next;
    }
}