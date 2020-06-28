# 025-Reverse Nodes in k-Group

[Problem](https://leetcode.com/problems/reverse-nodes-in-k-group/)

## Approach

The intuition is direct: reverse nodes in k-group and link the reversed sublists together. However, when it comes to implementation, there are two issues to be addressed:

1. If the number of nodes is not a multiple of k then the left-out nodes in the end should remain as it is.

2. What additional information are needed to link the reversed sublists together?

Issue 1 is easy to solve. I just need to first count the length of the list, then I can determine if there are sufficient number of left-out nodes to reverse.

For Issue 2, when linking a reversed sublist L_i to the previous sublist L_i-1, we link the head of L_i to the tail of L_i-1. To update the tail information, I also need to store the tail of L_i. In my implementation, the head of L_i is easy to get, as it is the last visited node during the reversing. On the contrary, the tail of L_i is the first visited node when the sublist is reversed, and needs to be stored beforehand. A trap is that the tail of the last reversed sublist links to its predecessor in the originial list, and we have to fix it after the main loop.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Count length
        int len{0};
        for (auto node = head; node; node = node->next) len++;

        ListNode dummy_head{-1};
        dummy_head.next = head;
        ListNode* prev{&dummy_head}; // Predecessor of the currently visited node in the original list
        ListNode* curr{head}; // Currently visited node
        ListNode* tail_prev_reverse_sublist{&dummy_head}; // The tail of the previous reversed sublist

        while (len >= k) {
            ListNode* tail_reverse_sublist{curr}; // The tail of the current reversed sublist

            // Reverse sublist
            for (auto i = 0; i < k; ++i) {
                ListNode* next_temp{curr->next};
                curr->next = prev;
                prev = curr;
                curr = next_temp;
            }
            // Now:
            // prev is the head of the current reversed sublist
            // curr is the node after the current reversed sublist

            // Link reversed sublist to the sublist before it
            tail_prev_reverse_sublist->next = prev;

            // Update variables
            tail_prev_reverse_sublist = tail_reverse_sublist;
            len -= k;
        }

        // Fix linking of the tail of the previous reversed sublist
        tail_prev_reverse_sublist->next = curr;

        return dummy_head.next;
    }
};
```
