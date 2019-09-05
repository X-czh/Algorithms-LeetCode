# 337-House Robber III

## Approach 1: Recursion

This is what I first came up with, you just decide whether or not you rob the current house. I initially thought this involved a lot of redundant computation, and the problem could be improved with tree dynamic programming. However, my thought turned out to be wrong.

Time complexity: O(n).

Space complexity: O(h) extra space.

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
    int rob(TreeNode* root) {
        auto p = robRecu(root);
        return max(p.first, p.second);
    }
private:
    pair<int, int> robRecu(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = robRecu(root->left);
        auto right = robRecu(root->right);

        int rob_root = root->val + left.second + right.second;
        int not_rob_root = max(left.first, left.second) + max(right.first, right.second);

        return {rob_root, not_rob_root};
    }
};
```
