/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

/** 
 * Naive Recursive Solution
 * Time Complexity: O(N^2)
 * Space Complexity: O(N)
 */
class Solution1 {
    public void reorderList(ListNode head) {
        if (head == null)
            return;
        
        ListNode tail = head, tailPred = head;
        while (tail.next != null) {
            tailPred = tail;
            tail = tail.next;
        }
        if (head != tail && head != tailPred) {
            tailPred.next = null;
            tail.next = head.next;
            head.next = tail;
            reorderList(tail.next);
        }
    }
}

/**
 * Iterative Version of the Naive Recursive Solution
 */ 
class Solution2 {
    public void reorderList(ListNode head) {
        while (head != null) {
            ListNode tail = head, tailPred = head;
            while (tail.next != null) {
                tailPred = tail;
                tail = tail.next;
            }
            if (head != tail && head != tailPred) {
                tailPred.next = null;
                tail.next = head.next;
                head.next = tail;
            }
            head = tail.next;
        }
    }
}

/**
 * Two Pointers
 */
