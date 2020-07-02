# 199-Binary Tree Right Side View

[Problem](https://leetcode.com/problems/binary-tree-right-side-view/)

## Approach 1: BFS: One Node Queue + One Depth Queue

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> right_side_view;
        queue<TreeNode*> node_q;
        queue<int> depth_q;
        node_q.push(root);
        depth_q.push(0);

        while (!node_q.empty()) {
            TreeNode* node = node_q.front();
            node_q.pop();
            int depth = depth_q.front();
            depth_q.pop();

            if (node->left) {
                node_q.push(node->left);
                depth_q.push(depth + 1);
            }
            if (node->right) {
                node_q.push(node->right);
                depth_q.push(depth + 1);
            }

            if (depth_q.empty() || depth_q.front() > depth) {
                right_side_view.push_back(node->val);
            }
        }

        return right_side_view;
    }
};
```

## Approach 2: BFS: Two Queues

Time complexity: O(n).

Space complexity: O(D), where D is the tree diameter.

```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        queue<TreeNode*> q;
        queue<TreeNode*> tmp;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) tmp.push(node->left);
            if (node->right) tmp.push(node->right);
            if (q.empty()) {
                res.push_back(node->val);
                swap(q, tmp);
            }
        }
        return res;
    }
};
```

## Approach 3: BFS: One Queue + Level Size Measurements

Time complexity: O(n).

Space complexity: O(D), where D is the tree diameter.

```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int level_len = q.size();
            for (int i = 0; i < level_len; i++) {
                auto node = q.front();
                q.pop();
                if (i == level_len - 1) {
                    res.push_back(node->val);
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};
```

## Approach 4: DFS

Time complexity: O(n).

Space complexity: O(H), where H is the tree height.

```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int level, vector<int>& res) {
        if (level == res.size()) {
            res.push_back(node->val);
        }

        if (node->right) {
            dfs(node->right, level + 1, res);
        }
        if (node->left) {
            dfs(node->left, level + 1, res);
        }
    }
};
```
