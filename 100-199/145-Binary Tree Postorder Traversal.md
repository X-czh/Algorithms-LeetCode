# 145-Binary Tree Postorder Traversal

[Problem](https://leetcode.com/problems/binary-tree-postorder-traversal/)

## Approach 1: Recursive

Time complexity: O(n).

Space complexity: O(n).

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> postorder;
        auto postorder_left = postorderTraversal(root->left);
        auto postorder_right = postorderTraversal(root->right);
        postorder.insert(postorder.end(), postorder_left.begin(), postorder_left.end());
        postorder.insert(postorder.end(), postorder_right.begin(), postorder_right.end());
        postorder.push_back(root->val);

        return postorder;
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        postorderTraversalRecu(root, postorder);
        return postorder;
    }
private:
    void postorderTraversalRecu(TreeNode* root, vector<int>& postorder) {
        if (root) {
            postorderTraversalRecu(root->left, postorder);
            postorderTraversalRecu(root->right, postorder);
            postorder.push_back(root->val);
        }
    }
};
```

## Approach 2: Iterative

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        deque<int> postorder;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            postorder.push_front(curr->val);
            if (curr->left) {
                s.push(curr->left);
            }
            if (curr->right) {
                s.push(curr->right);
            }
        }

        return vector<int>(postorder.begin(), postorder.end());
    }
};
```
