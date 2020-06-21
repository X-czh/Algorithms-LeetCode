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

// Recursion
// Time complexity: O(h) = O(logn).
// Space complexity: O(h) extra space.
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root, val);
    }
    
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) {
            auto new_node = new TreeNode(val);
            return new_node;
        }

        if (val < root->val) {
            root->left = insert(root->left, val);
            return root;
        } else {
            root->right = insert(root->right, val);
            return root;
        }
    }
};

// Iteration
// Time complexity: O(h) = O(logn).
// Space complexity: O(1) extra space.
class Solution2 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto node = root;
        while (node) {
            if (val < node->val) {
                if (!node->left) {
                    node->left = new TreeNode(val);
                    return root;
                } else {
                    node = node->left;
                }
            } else {
                if (!node->right) {
                    node->right = new TreeNode(val);
                    return root;
                } else {
                    node = node->right;
                }
            }
        }
        return new TreeNode(val);
    }
};