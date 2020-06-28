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
class Solution1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        
        if (val == root->val) {
            return root;
        } else if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};

// Iteration
// Time complexity: O(h) = O(logn).
// Space complexity: O(1) extra space.
class Solution2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && val != root->val)
            root = val < root->val ? root->left : root->right;
        return root;
    }
};
