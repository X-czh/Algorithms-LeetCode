/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode helpNode = new ListNode(-1);
        ListNode headNode = helpNode;
        
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                helpNode.next = l1;
                l1 = l1.next;
            } else {
                helpNode.next = l2;
                l2 = l2.next;
            }
            helpNode = helpNode.next;
        }
        
        if (l1 == null)
            helpNode.next = l2;
        else
            helpNode.next = l1;
        
        return headNode.next;
    }
}