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

// Approach: DFS
// Time complexity: O(n).
// Space complexity: O(h) extra space.

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        return countUnivalSubtreesHelper(root).first;
    }
private:
    pair<int, bool> countUnivalSubtreesHelper(TreeNode* root) {
        if (!root) {
            return {0, true};
        }
        
        int count = 0;
        bool isUnivalSubtree = false;
        auto left = countUnivalSubtreesHelper(root->left);
        auto right = countUnivalSubtreesHelper(root->right);
        
        count += left.first + right.first;
        if (left.second && right.second &&
           (!root->left || root->val == root->left->val) &&
           (!root->right || root->val == root->right->val)) {
            count += 1;
            isUnivalSubtree = true;
        }
        
        return {count, isUnivalSubtree};
    }
};
