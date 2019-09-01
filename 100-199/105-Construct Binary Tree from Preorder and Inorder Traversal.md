# 105-Construct Binary Tree from Preorder and Inorder Traversal

[Problem](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

## Approach 1

The first element of the preorder is the root value. Find the root value in inorder. As there is no duplicates, only one element is found. To the left of that found element are the elements of the left child tree and to the right are the elements of the right child tree. The second element of the preorder is the root value of the left child tree (if it is not empty, otherwise the root value of the right child tree). We can then recursively build the left and right child trees. Note that if we always build the left child trees before the right child trees, the sequence of the root values of the trees we are building is exactly the preorder sequence.

Time complexity: O(n^2).

Space complexity: O(n) extra space due to recursion.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_idx = 0;
        return buildTreeRecu(preorder, inorder, 0, inorder.size());
    }
private:
    int preorder_idx;

    TreeNode* buildTreeRecu(vector<int>& preorder, vector<int>& inorder, int inorder_start, int inorder_end) {
        if (inorder_start == inorder_end) return nullptr;

        TreeNode* root = new TreeNode{preorder[preorder_idx++]};

        if (inorder_start + 1 == inorder_end) return root;

        int inorder_root = inorder_start;
        while (inorder_root < inorder_end && inorder[inorder_root] != root->val) ++inorder_root;

        root->left = buildTreeRecu(preorder, inorder, inorder_start, inorder_root);
        root->right = buildTreeRecu(preorder, inorder, inorder_root + 1, inorder_end);

        return root;
    }
};
```

## Approach 2: Use Hash Map to store the position of the roots in inorder

Searching for the root value in inorder involves O(n) extra work in every recursive call. We can build a Hash Map to store the correspondence between the values and their indices in inorder. This reduces the searching for value extra work to O(1) in every recursive call at the cost of O(n) extra space for the hash map. 

Time complexity: O(n).

Space complexity: O(n) extra space.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_idx = 0;
        unordered_map<int, int> inorder_value_idx_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_value_idx_map.emplace(inorder[i], i);
        }
        return buildTreeRecu(preorder, inorder, 0, inorder.size(), inorder_value_idx_map);
    }
private:
    int preorder_idx;

    TreeNode* buildTreeRecu(vector<int>& preorder, vector<int>& inorder, int inorder_start, int inorder_end, unordered_map<int, int> &inorder_value_idx_map) {
        if (inorder_start == inorder_end) return nullptr;

        TreeNode* root = new TreeNode{preorder[preorder_idx++]};

        if (inorder_start + 1 == inorder_end) return root;

        int inorder_root = inorder_value_idx_map[root->val];

        root->left = buildTreeRecu(preorder, inorder, inorder_start, inorder_root, inorder_value_idx_map);
        root->right = buildTreeRecu(preorder, inorder, inorder_root + 1, inorder_end, inorder_value_idx_map);

        return root;
    }
};
```
