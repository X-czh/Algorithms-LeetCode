# 082-Remove Duplicates from Sorted List II

[Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

## Algorithm

Iterate through the list. Whenever find an element having the same value as the next element, remove it and all the subsequent elements with the same value.

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
        ListNode dummy_head{-1};
        dummy_head.next = head;
        ListNode* prev{&dummy_head};
        ListNode* curr{head};

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // Delete it and all subsequent elements with the same value
                int delete_val{curr->val};
                while (curr && curr->val == delete_val) {
                    prev->next = curr->next;
                    curr = curr->next;
                }
            } else {
                // Iterate normally
                prev = prev->next;
                curr = curr->next;
            }
        }

        return dummy_head.next;
    }
};
```

## Trap: Potential Memory Leakage

If we declare dummy_head as a pointer to ListNode and create the object on free store using new operator, we'll have to deallocate the memory manually before the function returns to avoid memory leakage.
