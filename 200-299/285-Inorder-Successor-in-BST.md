# 285-Inorder Successor in BST

[Problem](https://leetcode.com/problems/inorder-successor-in-bst/)

## Approach: Iterative Inorder Traversal

There could be two situations: If the node has a right child, the successor can be found by take one step right and then left till you can.Otherwise, the successor is somewhere upper in the tree, and can be found with iterative inorder traversal.

Time complexity: O(H), where H is tree height.

Space complexity: O(1) extra space in the best case where the node p has a right child, otherwise up to O(H) to keep the stack.

```c++
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // the successor is somewhere lower in the right subtree
        // successor: one step right and then left till you can
        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }

        stack<TreeNode*> s;
        TreeNode* curr = root;
        int prevVal = (p->val == numeric_limits<int>::min()) ? p->val - 1 : p->val + 1;

        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            if (prevVal == p->val) {
                return curr;
            }
            prevVal = curr->val;
            curr = curr->right;
        }

        return nullptr;
    }
};
```
