# 083-Remove Duplicates from Sorted List

[Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

## Algorithm

Iterate through the list. Whenever find an element having the same value as the next element, remove all the subsequent elements with the same value. Compare to Problem 082, we do not need a dummy_head, as the head of the list will be kept unchanged; we do not need to keep track of the previous node as well, as we will only be deleting the nodes after the currently visited node.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr{head};

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
```
