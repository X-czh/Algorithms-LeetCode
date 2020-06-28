# 328-Odd Even Linked List

[Problem](https://leetcode.com/problems/odd-even-linked-list/)

## Approach

Put the odd nodes in a linked list and the even nodes in another. Then link the even list to the tail of the odd list. I intially wrote Solution1, and later found it could be simplified to Solution2.

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
class Solution1 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!(head) || !(head->next) || !(head->next->next)) return head;

        ListNode* even_head{head->next};
        ListNode* odd_tail{head};
        ListNode* even_tail{even_head};
        ListNode* odd_ptr{odd_tail->next->next};
        ListNode* even_ptr{even_tail->next->next};

        while (odd_ptr && even_ptr && even_ptr->next) {
            odd_tail->next = odd_ptr;
            odd_tail = odd_ptr;
            odd_ptr = odd_ptr->next->next;
            even_tail->next = even_ptr;
            even_tail = even_ptr;
            even_ptr = even_ptr->next->next;
        }
        if (odd_ptr) {
            odd_tail->next = odd_ptr;
            odd_tail = odd_ptr;
        }
        if (even_ptr) {
            even_tail->next = even_ptr;
            even_tail = even_ptr;
        }

        // Link odd list and even list together
        odd_tail->next = even_head;
        even_tail->next = nullptr;

        return head;
    }
};

class Solution2 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        ListNode* odd{head};
        ListNode* even{head->next};
        ListNode* even_head{even};

        // Invariant: elements before even is not nullptr
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = even_head;

        return head;
    }
};
```
