# 111-Minimum Depth of Binary Tree

[Problem](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

## Algorithm

This may look like getting min depth. But the trap is NULL node. Depth for NULL node is short but it's not the LEAF node. So we should ignore NULL node.

Time complexity: O(n).

Space complexity: O(n) due to recursion.

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (left > 0 && right > 0) {
            return 1 + min(left, right);
        } else {
            return 1 + (left + right);
        }
    }
};
```
