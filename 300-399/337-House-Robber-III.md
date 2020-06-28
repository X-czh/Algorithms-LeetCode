# 337-House Robber III

## Approach 1: Recursion

This is what I first came up with, you just decide whether or not you rob the current house.

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

## Approach 2: Dynamic Programming On Trees

This can also be solved by using dynamic programming on trees (instead of the usual multidimensional array). However, redundant computation of the overlapping subproblems can be easily avoided by using a clever form of DFS as in Approach 1.

Time complexity: O(n).

Space complexity: O(n) extra space (can be optimized to O(h) as well).

```c++
struct DPTreeNode {
    int rob;
    int not_rob;
    DPTreeNode* left;
    DPTreeNode* right;
    DPTreeNode() : rob(0), not_rob(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;

        auto dp_root = new DPTreeNode();
        dfs(root, dp_root);
        return max(dp_root->rob, dp_root->not_rob);
    }
private:
    void dfs(TreeNode* curr, DPTreeNode *dp_node) {
        int left_rob = 0;
        int left_not_rob = 0;
        int right_rob = 0;
        int right_not_rob = 0;

        if (curr->left) {
            dp_node->left = new DPTreeNode();
            dfs(curr->left, dp_node->left);
            left_rob = dp_node->left->rob;
            left_not_rob = dp_node->left->not_rob;
        }

        if (curr->right) {
            dp_node->right = new DPTreeNode();
            dfs(curr->right, dp_node->right);
            right_rob = dp_node->right->rob;
            right_not_rob = dp_node->right->not_rob;
        }

        dp_node->rob = curr->val + left_not_rob + right_not_rob;
        dp_node->not_rob = max(left_rob, left_not_rob) + max(right_rob, right_not_rob);
    }
};
```
