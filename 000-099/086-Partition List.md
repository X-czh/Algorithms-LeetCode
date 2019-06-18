# 086-Partition List

[Problem](https://leetcode.com/problems/partition-list/)

## Algorithm

Our goal is to reform the linked list structure, such that the elements lesser than a certain value x, come before the elements greater or equal to x, and the original relative order of the nodes in each of the two partitions are preserved.

The idea of our approach is straight foward: find the first element that is greater than or equal to x (pivot), and iterate the remaining elements in order, move the elements less than x before the pivot.

To implement this, we need to keep track of the pivot and the currently-visited element. In addition, we have to record the elements right before the pivot and the currently-visited element because we are manipulating a singly-linked list, where information of the predcessor of a specific element is required for performing insertion and deletion of that element. In case the first element is the pivot, a dummy element is inserted in the front. It acts as the predecessor of the pivot in that case.

Time complexity: O(n).

Space complexity: O(1).

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Construct dummy head
        ListNode dummy{-1};
        dummy.next = head;
        ListNode* prev_head = &dummy;

        // Locate pivot: the first element that is greater than or equal to x
        while (head && head->val < x) {
            head = head->next;
            prev_head = prev_head->next;
        }
        ListNode* pivot = head;
        ListNode* prev_pivot = prev_head;

        // Move all following nodes that are less than x before pivot
        while (head) {
            if (head->val < x) {
                // Move node before pivot
                prev_head->next = head->next;
                prev_pivot->next = head;
                head->next = pivot;

                // Move prev_pivot ptr
                prev_pivot = head;

                // Move head ptr
                head = prev_head->next;
            } else {
                head = head->next;
                prev_head = prev_head->next;
            }
        }

        return dummy.next;
    }
};
```
