# 445-Add Two Numbers II

[Problem](https://leetcode.com/problems/add-two-numbers-ii/)

## Approach: Stack

In [002-Add Two Numbers](https://leetcode.com/problems/add-two-numbers/), the least significant digit comes first in the input lists, which are easy to manipulate. Here, the most significant digit comes first. We can directly reversed the input lists, but this means we have to modify the input list. Alternatively, we can use stack.

Time complexity: O(n).

Space complexity: O(n).

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        for (auto node = l1; node; node = node->next) {
            s1.push(node->val);
        }
        for (auto node = l2; node; node = node->next) {
            s2.push(node->val);
        }

        int carry = 0;
        ListNode* curr{nullptr};
        ListNode* next{nullptr};
        while (!s1.empty() && !s2.empty()) {
            int sum = s1.top() + s2.top() + carry;
            int val = sum % 10;
            carry = sum / 10;

            curr = new ListNode{val};
            curr->next = next;
            next = curr;

            s1.pop();
            s2.pop();
        }

        while (!s1.empty()) {
            int sum = s1.top() + carry;
            int val = sum % 10;
            carry = sum / 10;

            curr = new ListNode{val};
            curr->next = next;
            next = curr;

            s1.pop();
        }

        while (!s2.empty()) {
            int sum = s2.top() + carry;
            int val = sum % 10;
            carry = sum / 10;

            curr = new ListNode{val};
            curr->next = next;
            next = curr;

            s2.pop();
        }

        if (carry > 0) {
            curr = new ListNode{carry};
            curr->next = next;
        }

        return curr;
    }
};
```
