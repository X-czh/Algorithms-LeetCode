// Time complexity: O(n)
// Space complexity: O(n)

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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
private:
    bool isValidBSTHelper(TreeNode* root, long lower, long upper) {
        if (!root) return true;
        
        int val = root->val;
        return (val > lower && val < upper &&
                isValidBSTHelper(root->left, lower, val) &&
                isValidBSTHelper(root->right, val, upper));
    }
};
