// Time complexity: O(n).
// Space complexity: O(h) extra space.

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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        return isUnivalTreeRecu(root, root->val);
    }
private:
    bool isUnivalTreeRecu(TreeNode* root, int val) {
        if (!root) return true;
        if (root->val != val) return false;
        return isUnivalTreeRecu(root->left, val) && isUnivalTreeRecu(root->right, val);
    }
};
