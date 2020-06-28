# 513-Find Bottom Left Tree Value

[Problem](https://leetcode.com/problems/find-bottom-left-tree-value/)

## Approach 1: Keep track of depth of curr and prev TreeNodes

We can keep track of the depth of the nodes when doing BFS. To track the depth, we can use a hash map (like in Solution 1), or use a depth queue that operates simutaneously with the normal BFS queue (like in Solution 2).

Time complexity: O(n).

Space complexity: O(2 * n) extra space.

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
class Solution1 {
public:
    int findBottomLeftValue(TreeNode* root) {
        assert(root != nullptr);

        queue<TreeNode*> q;
        q.push(root);

        unordered_map<TreeNode*, int> depth;
        depth[root] = 0;

        TreeNode* prev = nullptr;
        int bottom_left_tree_value = 0;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            auto left = curr->left;
            if (left) {
                q.push(left);
                depth[left] = depth[curr] + 1;
            }
            auto right = curr->right;
            if (right) {
                q.push(right);
                depth[right] = depth[curr] + 1;
            }

            if (depth[curr] == 0 || depth[curr] > depth[prev]) {
                bottom_left_tree_value = curr->val;
            }

            prev = curr;
        }

        return bottom_left_tree_value;
    }
};

class Solution2 {
public:
    int findBottomLeftValue(TreeNode* root) {
        assert(root != nullptr);

        queue<TreeNode*> q;
        q.push(root);

        queue<int> depth_q;
        depth_q.push(0);
        int prev_depth = -1;

        int bottom_left_tree_value = 0;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            int curr_depth = depth_q.front();
            q.pop();
            depth_q.pop();

            auto left = curr->left;
            if (left) {
                q.push(left);
                depth_q.push(curr_depth + 1);
            }
            auto right = curr->right;
            if (right) {
                q.push(right);
                depth_q.push(curr_depth + 1);
            }

            if (curr_depth > prev_depth) {
                bottom_left_tree_value = curr->val;
            }

            prev_depth = curr_depth;
        }

        return bottom_left_tree_value;
    }
};
```

## Approach 2: BFS, visit right nodes first

Elegant.

Time complexity: O(n).

Space complexity: O(n) extra space.

```c++
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        assert(root != nullptr);

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* curr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr->right) q.push(curr->right);
            if (curr->left) q.push(curr->left);
        }

        return curr->val;
    }
};
```
