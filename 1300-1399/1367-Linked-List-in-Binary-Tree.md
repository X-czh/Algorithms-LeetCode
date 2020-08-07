# 1367-Linked List in Binary Tree

[Problem](https://leetcode.com/problems/linked-list-in-binary-tree/)

## Approach

BFS the tree, from each node in the binary tree, check if all the elements in the linked list starting from the head correspond to some downward path in the binary tree.

Time complexity: O(Nlog(N)).

Space complexity: O(N) extra space.

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (helper(head, node)) {
                return true;
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return false;
    }

private:
    // Given a pointer in a Linked List and any node in the Binary Tree.
    // Check if all the elements in the linked list starting from the head correspond to some downward path in the binary tree.
    bool helper(ListNode* head, TreeNode* root) {
        if (head->val == root->val) {
            if (!head->next) {
                return true;
            }

            bool left = false;
            bool right = false;
            if (root->left) {
                left = helper(head->next, root->left);
            }
            if (root->right) {
                right = helper(head->next, root->right);
            }
            return left || right;
        }
        return false;
    }
};
```
