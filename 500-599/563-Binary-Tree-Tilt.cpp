// Time complexity: O(n).
// Space complexity: O(h) extra space.

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
class Solution {
public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        visit(root, tilt);
        return tilt;
    }
private:
    int visit(TreeNode* root, int& tilt) {
        if (!root) return 0;
        int left = visit(root->left, tilt);
        int right = visit(root->right, tilt);
        tilt += abs(left - right);
        return left + right + root->val;
    }
};
