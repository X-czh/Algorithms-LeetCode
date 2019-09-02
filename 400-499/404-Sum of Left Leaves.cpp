// Time complexity: O(n)
// Space complexity: O(h)

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        
        int left_sum = 0;
        int right_sum = 0;
        TreeNode* left_child = root->left;
        TreeNode* right_child = root->right;
        
        if (left_child) {
            if (!left_child->left && !left_child->right) {
                left_sum = left_child->val;
            } else {
                left_sum = sumOfLeftLeaves(left_child);
            }
        }
        
        if (right_child) {
            right_sum = sumOfLeftLeaves(right_child);
        }
        
        return left_sum + right_sum;
    }
};