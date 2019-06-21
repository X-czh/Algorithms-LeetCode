# 876-Middle of the Linked Lists

[Problem](https://leetcode.com/problems/middle-of-the-linked-list/)

## Approach 1: Get the length first, then go to the middle

Time complexity: O(3/2 n).

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
    ListNode* middleNode(ListNode* head) {
        // Get length of list
        int len = 0;
        for (auto node = head; node; node = node->next) len++;

        // Go to middle
        ListNode* curr = head;
        for (auto i = 1; i != len / 2; ++i) {
            curr = curr->next;
        }
        return curr;
    }
};
```

## Approach 2: Output to Array

Put every node into an array A in order, then the middle node is just A[A.length // 2].

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> v{};
        for (auto node = head; node; node = node->next) {
            v.push_back(node);
        }
        return v[v.size() / 2];
    }
};
```

## Approach 3: Fast and Slow Pointer

When traversing the list with a pointer slow, make another pointer fast that traverses twice as fast. When fast reaches the end of the list, slow must be in the middle.

Time complexity: O(3/2 n).

Space complexity: O(1).

```c++
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```
