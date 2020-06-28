# 109-Convert Sorted List to Binary Search Tree

[Problem](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

## Approach 1: Recursion

To construct a heigtbinary search tree with a sorted list a1...an, first select a number ai to be the root, then construct the left child tree with numbers 1 ... a(i-1) and the right child tree with numbers a(i+1) ... an.

Time complexity: O(nlogn).

Space complexity: O(logn).

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for (auto curr = head; curr; curr = curr->next) len++;
        return sortedListToBSTHelper(head, len);
    }
private:
    TreeNode* sortedListToBSTHelper(ListNode* head, int length) {
        if (length == 0) return nullptr;
        if (length == 1) return new TreeNode(head->val);

        ListNode* mid = head;
        for (int i = 0; i < length / 2; i++) {
            mid = mid->next;
        }

        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBSTHelper(head, length / 2);
        root->right = sortedListToBSTHelper(mid->next, length - length / 2 - 1);

        return root;
    }
};
```
