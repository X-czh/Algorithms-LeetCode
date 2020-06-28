# 095-Unique Binary Search Trees II

[Problem](https://leetcode.com/problems/unique-binary-search-trees-ii/)

## Algorithm: Dynamic Programming

To construct a binary search tree B_n with numbers 1 ... n, first select a number x to be the root, then construct the left child tree with numbers 1 ... x-1 and the right child tree with numbers x+1 ... n. Note that the unique binary search trees constructed with x+1 ... n are isomorphic with those constructed with 1 ... n-x. Therefore, we can build a B_n with root x with a left tree from the B(x-1) family and a right tree from the B(n-x) family (we only need to successivly add each node's val by x).

Time complexity: O(nC(n)), where C(n) is the nth Catalan number.

Space complexity: ? (a lot of sub-structures are reused).

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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};

        vector<vector<TreeNode*>> mem;
        mem.push_back({nullptr});

        for (auto i = 1; i <= n; ++i) {
            vector<TreeNode*> forest;
            for (auto j = 1; j <= i; ++j) {
                for (auto left_tree : mem[j - 1]) {
                    for (auto right_tree : mem[i - j]) {
                        auto root = new TreeNode{j};
                        root->left = left_tree;
                        root->right = copy_update(right_tree, j);
                        forest.push_back(root);
                    }
                }
            }
            mem.push_back(forest);
        }

        return mem.back();
    }
private:
    TreeNode* copy_update(TreeNode* root, int i) {
        if (!root) return nullptr;

        auto new_root = new TreeNode{root->val + i};
        new_root->left = copy_update(root->left, i);
        new_root->right = copy_update(root->right, i);

        return new_root;
    }
};
```
