# 237-Delete Node in a Linked List

[Problem](https://leetcode.com/problems/delete-node-in-a-linked-list/)

## Approach

We want to delete a node (except the tail) in a singly linked list. However, we are given only access to that node and we do not know the node before it. We can replace its value with the value of the node after it, and then make it directly point to the node after the node after it.

Time complexity: O(1).

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```
