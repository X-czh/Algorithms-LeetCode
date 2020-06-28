# 369-Plus One Linked List

[Problem](https://leetcode.com/problems/plus-one-linked-list/)

## Approach 1: Sentinel Head + Textbook Addition

Identify the rightmost digit which is not equal to nine and increase that digit by one. All the following nines should be set to zero. Usea sentinel head to handle the case of overflowing (eg. add 1 to 999).

Time complexity: O(n).

Space complexity: O(1).

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        auto sentinel = new ListNode(0, head);
        auto not_nine = sentinel;
        
        auto curr = head;
        while (curr) {
            if (curr->val != 9) {
                not_nine = curr;
            }
            curr = curr->next;
        }
        
        not_nine->val++;
        not_nine = not_nine->next;
        
        while (not_nine) {
            not_nine->val = 0;
            not_nine = not_nine->next;
        }
        
        if (sentinel->val == 0) {
            delete sentinel;
            return head;
        } else {
            return sentinel;
        }
    }
};
```
