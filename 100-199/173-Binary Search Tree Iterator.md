# 173-Binary Search Tree Iterator

[Problem](https://leetcode.com/problems/binary-search-tree-iterator/)

## Approach 1: Controlled Inorder Traversal

Use a custom stack to simulate the inorder traversal. We only need to inorder traversal to the leftmost to get the smallest element, add the nodes to the stack along the way. When popping a node, we do the same process to its right node (if exists).

Time complexity: O(1) for hasNext(); for next(), best O(1), worst O(n).

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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverse_leftmost(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* next_node = s.top();
        int next_val = next_node->val;
        s.pop();

        traverse_leftmost(next_node->right);

        return next_val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
private:
    stack<TreeNode*> s;

    void traverse_leftmost(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
