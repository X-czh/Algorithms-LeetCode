# 206-Reverse Linked List

[Problem](https://leetcode.com/problems/reverse-linked-list/)

## Approach 1: Iterative

Iteratively reverse the link of node -> remaining list to be node <- remaining list.

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev{};
        ListNode* curr{head};

        while (curr) {
            ListNode* next_temp{curr->next};
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }

        return prev;
    }
};
```

## Approach 2: Recursive

**Base case:** list of length 0 or 1 need no modification.

**Recursive step:** reverse(x :: L) = reverse(L) :: x.

Time complexity: O(n).

Space complexity: O(n). The extra space comes from implicit stack space due to recursion. The recursion could go up to n levels deep.

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* p = reverseList(head->next); // after which head->next is the tail of that list
        head->next->next = head;
        head->next = nullptr;

        return p;
    }
};
```
