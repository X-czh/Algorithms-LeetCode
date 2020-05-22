// Time complexity: O(n).
// Space complexity: O(H).

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root)
            return nullptr;

        bool changed = false;
        do {
            changed = removeLeafNodesHelper(root, target);
        } while (changed);
        
        if (!root->left && !root->right && root->val == target)
            return nullptr;
        
        return root;
    }
private:
    bool removeLeafNodesHelper(TreeNode* root, int target) {
        bool changed = false;

        TreeNode* leftTree = root->left;
        if (leftTree) {
            if (!leftTree->left && !leftTree->right) {
                if (leftTree->val == target) {
                    delete(root->left);
                    root->left = nullptr;
                    changed = true;
                }
            } else {
                changed |= removeLeafNodesHelper(leftTree, target);
            }
        }
        
        TreeNode* rightTree = root->right;
        if (rightTree) {
            if (rightTree && !rightTree->left && !rightTree->right) {
                if (rightTree->val == target) {
                    delete(root->right);
                    root->right = nullptr;
                    changed = true;
                }
            } else {
                changed |= removeLeafNodesHelper(rightTree, target);
            }
        }

        return changed;
    }
};
