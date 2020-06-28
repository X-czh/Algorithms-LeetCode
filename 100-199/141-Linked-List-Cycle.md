# 141-Linked List Cycle

[Problem](https://leetcode.com/problems/linked-list-cycle/)

## Approach 1: Hash Table

Time complexity: O(n).

Space complexity: O(n).

## Approach 2: Two Pointers: Floyd's Tortoise and Hare

Imagine there are two people A and B start from the same point, A is twice fast as B. If they are chasing along a cyclic route, they are sure to meet again, otherwise not. Here, we use two pointers, one fast, one slow, chasing each other. The algorithm was credited to Robert W. Floyd by Donald Knuth (a potential misattribution), and is also called the "tortoise and the hare algorithm".

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
```
