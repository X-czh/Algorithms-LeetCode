# 124-Binary Tree Maximum Path Sum

[Problem](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

## Approach

For each node n in tree, compute the max path sum that starts with n and only goes downward. With that, we can compute the max path sum of a roof-shaped path with the roof peak as n for each node n in tree, and the maximum path sum of this kind is what we want to compute.

Time complexity: O(n).

Space complexity: O(n).

```c++
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
    int maxPathSum(TreeNode* root) {
        maxDownwardPathSum(root);
        return maxSum;
    }
private:
    int maxSum = numeric_limits<int>::min();

    int maxDownwardPathSum(TreeNode* node) {
        if (!node) return 0;

        // max(max downward path sum from node->left, 0)
        int left = max(maxDownwardPathSum(node->left), 0);
        // max(max downward path sum from node->right, 0)
        int right= max(maxDownwardPathSum(node->right), 0);

        // construct a max path sum from left and right
        int newPathSum = node->val + left + right;

        // update global maxSum
        maxSum = max(maxSum, newPathSum);

        return node->val + max(left, right);
    }
};
```
