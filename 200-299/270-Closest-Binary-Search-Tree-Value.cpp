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

// Recursive binary search
// Time complexity: O(H).
// Space complexity: O(H).
class Solution1 {
public:
    int closestValue(TreeNode* root, double target) {
        double curr_diff = abs(root->val - target);

        int value = 0;
        if (root->val > target && root->left) {
            value = closestValue(root->left, target);
        } else if (root->val < target && root->right) {
            value = closestValue(root->right, target);
        } else {
            return root->val;
        }

        return (abs(value - target) < curr_diff) ? value : root->val;
    }
};

// Iterative binary search
// Time complexity: O(H).
// Space complexity: O(1).
class Solution2 {
public:
    int closestValue(TreeNode* root, double target) {
        int val;
        int closest = root->val;
        
        while (root) {
            val = root->val;
            if (abs(val - target) < abs(closest - target)) {
                closest = val;
            }
            root = target < val ? root->left : root->right;
        }

        return closest;
    }
};
